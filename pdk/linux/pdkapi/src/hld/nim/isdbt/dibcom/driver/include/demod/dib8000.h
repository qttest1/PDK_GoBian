#ifndef DEMOD_DIB8000_H
#define DEMOD_DIB8000_H

#include <demod/dibx000_common.h>

#ifdef __cplusplus
extern "C" {
#endif

//! Configuration of one demodulator
/**
 * This struct is used to configure the DiB8000-demod-driver to make it handle an IC on a specific board correctly.
 */
struct dib8000_config {
    uint8_t output_mpeg2_in_188_bytes; /*! indicates if the demod shall output the MPEG2-TS as 188 or 204 bytes */
    uint8_t hostbus_diversity; /*! use hostbus for diversity out or standard diversity out (or nothing in single mode) */

    /**
     * callback of the demodulator to set up an LNA.
     * @param demod is the demod-context
     * @param agc_global is the value n_agc_global - it is used for the implementation to know if the LNA-status can be changed or not.
     * @return you have to return 1 when the LNA-status has changed otherwise 0 (when 1 is returned the demod restarts its AGC)
     */
    int (*update_lna) (struct dibFrontend *demod, uint16_t agc_global);

    uint8_t agc_config_count;
    const struct dibx000_agc_config *agc; /*! AGC parameters struct dib7000m_agc_config */

    const struct dibx000_bandwidth_config *pll; /*! Bandwidth parameters struct dib7000m_bandwidth_parameter */

    /**
     * Initial GPIO setup
     */
#define DIB8000_GPIO_DEFAULT_DIRECTIONS 0xffff
    uint16_t gpio_dir; /*! Initial GPIO directions */

#define DIB8000_GPIO_DEFAULT_VALUES     0x0000
    uint16_t gpio_val; /*! Initial GPIO values */

#define DIB8000_GPIO_PWM_POS0(v)        ((v & 0xf) << 12)
#define DIB8000_GPIO_PWM_POS1(v)        ((v & 0xf) << 8 )
#define DIB8000_GPIO_PWM_POS2(v)        ((v & 0xf) << 4 )
#define DIB8000_GPIO_PWM_POS3(v)         (v & 0xf)
#define DIB8000_GPIO_DEFAULT_PWM_POS    0xffff
    uint16_t gpio_pwm_pos; /*! Initial GPIO PWM Positions */

    uint16_t pwm_freq_div; /*! set the frequency divider for PWM */

    /**
     * a callback called, before and after an AGC restart of the demod,
     * @before indicates if the call is before or after
     */
    int (*agc_control) (struct dibFrontend *, uint8_t before);

    /**
     * define the pad-drive-settings for this demod, 0 sets some defaults, which are most likely not right.
     */
    uint16_t drives;
    uint16_t diversity_delay;
    uint16_t div_cfg;
    uint8_t refclksel;
};

#define DEFAULT_DIB8000_I2C_ADDRESS 18

//! Register one DiB8000-demodulator to a Frontend using I2C
/**
 * This function can be used to register a DiB8000-demodulator connected to an I2C-bus to a frontend. It represents the digital demodulator part of a frontend. Registering an RF tuner make the frontend complete and usable.
 * \param fe dibFrontend to register this demod to
 * \param host the DataBusHost (I2C-Adapter) which can be used to reach this demodulator
 * \param i2c_addr I2C of this demodulator on the I2C-Bus
 * \param cfg pointer to a configuration-struct describing the demod-setup. Has to be given by the caller.
 * \return fe on success , NULL otherwise.
 */
extern struct dibFrontend * dib8000_register(struct dibFrontend *fe, struct dibDataBusHost *host, uint8_t i2c_addr, const struct dib8000_config *cfg);

//! Do the I2C-enumeration of DiB8000-demodulator on one I2C bus
/**
 * This function must be used to enumerate DiB8000-devices on an I2C-bus. This is necessary in a multi-demod-setup (such as diversity).
 * \param host the DataBusHost (I2C-Adapter) which can be used to reach the devices
 * \param no_of_demods the number of the device to enumerate
 * \param default_addr the default I2C address of all devices
 * \param first_addr this will be the address of the first enumerated device, the second one will have first_addr+2, the third one first_addr+4 and so on
 * \return DIB_RETURN_SUCCESS on success, something else otherwise
 */
extern int dib8000_i2c_enumeration(struct dibDataBusHost *host, int no_of_demods, uint8_t default_addr, uint8_t first_addr);

extern void dib8000_close_gate(struct dibFrontend *fe);
extern void dib8000_enable_output_clock(struct dibFrontend *fe);

//! get the struct dibDataBusHost for a specific demod
/**
 * This function gives you access to the different I2C-Interfaces (and methods) of the DiB8000 by returning the appropriate pointer to a struct dibDataBusHost.
 * \param demod specifies the demod to use as I2C-master
 * \param intf specifies the interface
 * \param gating indicates if the I2C-Adapter is just opening the gate instead of using the I2C-master for transmitting the I2C-message. (Works only, if the demod itself is on an I2C-bus).
 * \return reference to the appropriate I2C-Adapter or NULL in case of an error
 */
extern struct dibDataBusHost * dib8000_get_i2c_master(struct dibFrontend *demod, enum dibx000_i2c_interface intf, int gating);

//! enabled the VBG voltage of the ADC
/**
 * On some boards it is necessary to enabled the VBG voltage of the ADC, while
 * the demod is powered off, to improve reception quality of the Analog-Chip.
 */
extern int dib8000_enable_vbg_voltage(struct dibFrontend *demod);

//! toggle the diversity configuration between hostbus-diversity and standard-div/sram-div
extern void dib8000_set_hostbus_diversity(struct dibFrontend *demod, uint8_t onoff);

//! do some post tune updates of internal states to improve portable performance
extern int dib8000_post_tune_adaptation(struct dibFrontend *demod);

//! enable the PWM-modulator on GPIOs
extern int dib8000_set_pwm_gpio(struct dibFrontend *fe, uint8_t num, uint8_t id, uint8_t freq, uint32_t value);

//! read the raw AGC global value
extern uint16_t dib8000_get_current_agc_global(struct dibFrontend *demod);

extern int32_t dib8000_get_adc_power(struct dibFrontend *fe, uint8_t mode);

//! exported AGC startup function
extern int dib8000_agc_startup(struct dibFrontend *fe, struct dibChannel *ch);
extern void dib8000_pwm_agc_reset(struct dibFrontend *fe, struct dibChannel *ch);

//! Attaching one or more DiB8000-demodulators using I2C-bus
/**
 * This function is only provided for backward compatibility. Please use dib8000_register.
 */
extern int dib8000_attach(struct dibDataBusHost *i2c_adap, int no_of_demods, uint8_t default_addr, uint8_t do_i2c_enum, const struct dib8000_config cfg[], struct dibFrontend *demod[]);

extern void dib8000_tune_reset_fes(struct dibFrontend *fe[], uint32_t num_fe);
//extern int dib8000_update_pll(struct dibFrontend *fe, struct dibx000_bandwidth_config *pll);
#ifdef __cplusplus
}
#endif

#endif
