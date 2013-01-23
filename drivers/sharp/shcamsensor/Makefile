obj-$(CONFIG_SH_CAMERA) += sh_maincamdrv.o

obj-$(CONFIG_SH_CAMERA) += sh_maincam_power_ctrl.o

ifeq ($(USES_SH_SUBCAMERA_FWVGA),yes)
	obj-$(CONFIG_SH_CAMERA) += sh_subcamdrv.o
else ifeq ($(USES_SH_SUBCAMERA_VGA_OV),yes)
	obj-$(CONFIG_SH_CAMERA) += sh_subcamdrv.o
endif
