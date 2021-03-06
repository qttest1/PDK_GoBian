#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

//#define NO_FE_COMPONENT_BACKWARD_COMPAT
//#define NO_I2C_ADAPTER_BACKWARD_COMPAT
//#define NO_DVBCHANNEL_BACKWARD_COMPAT
#define NO_SHARED_TUNER

//#define CONFIG_DEBUG
#define CONFIG_BUILD_HOST
#define DIBCOM_EXTENDED_MONITORING
//#define DIBCOM_GENERIC_MONITORING

#define CONFIG_STANDARD_DVBT
//#define CONFIG_STANDARD_DAB
#define CONFIG_STANDARD_ISDBT
//#define CONFIG_STANDARD_ANALOG

#define CONFIG_BAND_VHF
#define CONFIG_BAND_CBAND
#define CONFIG_BAND_UHF
#define CONFIG_BAND_LBAND
#define CONFIG_BAND_SBAND

//#define CONFIG_NO_TUNE_ASYNC

//set the output mode (parallel gated (OUTPUT_MODE_TS_PARALLEL_GATED),
//parallel cont (OUTPUT_MODE_TS_PARALLEL_CONT), serial (OUTPUT_MODE_TS_SERIAL) or off (OUTPUT_MODE_OFF))
//the different values are defined in driver/include/adapter/common.h
#define CONFIG_OUTPUT_MODE OUTMODE_MPEG2_SERIAL//OUTMODE_MPEG2_PAR_GATED_CLK

#define CONFIG_DEMOD_I2C_CHUNK_SIZE 125

#define CONFIG_DIB0090_USE_PWM_AGC

#define CONFIG_FIRMWARE_PATH ""

#define __unix__
#define __KERNEL__

#endif
