#
# Makefile for MCAPI driver
#


obj-y          += libmcapi.o

libmcapi-y :=   mcapi_hi.o \
				mcapi_cfg.o \
				cntrl_msg.o \
				connect.o \
				create_endpoint.o \
				data_avail.o \
				data_count.o \
				endpoint.o \
				forward.o \
				get_endp.o \
				handle.o \
				interface.o \
				mcapi_cancel.o \
				mcapi_connect_pktchan_i.o \
				mcapi_connect_sclchan_i.o \
				mcapi_create_endp.o \
				mcapi_delete_endp.o \
				mcapi_finalize.o \
				mcapi_get_endp_attrib.o \
				mcapi_get_endp_i.o \
				mcapi_get_endp.o \
				mcapi_get_node_id.o \
				mcapi_init.o \
				mcapi_msg_avail.o \
				mcapi_msg_rcv_i.o \
				mcapi_msg_rcv.o \
				mcapi_msg_snd_i.o \
				mcapi_msg_snd.o \
				mcapi_open_pktchan_rcv_i.o \
				mcapi_open_pktchan_snd_i.o \
				mcapi_open_sclchan_rcv_i.o \
				mcapi_open_sclchan_snd_i.o \
				mcapi_pktchan_avail.o \
				mcapi_pktchan_free.o \
				mcapi_pktchan_rcv_close_i.o \
				mcapi_pktchan_rcv_i.o \
				mcapi_pktchan_rcv.o \
				mcapi_pktchan_snd_close_i.o \
				mcapi_pktchan_snd_i.o \
				mcapi_pktchan_snd.o \
				mcapi_sclchan_avail.o \
				mcapi_sclchan_rcv_close_i.o \
				mcapi_sclchan_rcv_u16.o \
				mcapi_sclchan_rcv_u32.o \
				mcapi_sclchan_rcv_u64.o \
				mcapi_sclchan_rcv_u8.o \
				mcapi_sclchan_snd_close_i.o \
				mcapi_sclchan_snd_u16.o \
				mcapi_sclchan_snd_u32.o \
				mcapi_sclchan_snd_u64.o \
				mcapi_sclchan_snd_u8.o \
				mcapi_set_endp_attrib.o \
				mcapi_test.o \
				mcapi_wait_any.o \
				mcapi_wait.o \
				msg_rcv.o \
				msg_snd.o \
				node_data.o \
				node.o \
				pkt_rcv.o \
				pkt_snd.o \
				request.o \
				route.o \
				scal_rcv.o \
				scal_snd.o \
				suspend.o \
				mcapi_tls.o \
				shm.o \
				shm_os.o \
				mcapi_os.o \
				mcapi_queue.o \
				pr_malloc.o \
				pr_thread.o \
				pr_mutex.o \
				pr_cond.o \
				pr_semaphore.o \
				pr_sleep.o

EXTRA_CFLAGS += -D__ALI_LINUX_KERNEL__ -D__MIPS32__ -D__MCAPI_TEST__ -I./ -I$(ALIDRIVERS_DIR)/alimcomm/


