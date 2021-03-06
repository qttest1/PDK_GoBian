#/bin/sh

# use shell funcs
. $LINUX_SRC_DIR/../tools/hosttools/funcs.sh
IMAGE_ROOTFS_DIR=$LINUX_SRC_DIR/install/fs
HOSTTOOLS_DIR=$LINUX_SRC_DIR/../tools/hosttools
IMAGES_DIR=$LINUX_SRC_DIR/install/bin

echo
echo "separate fs for flash with 8KiB-page 4GiB-size..."

# ubi partition and cfg name
ROOTFS_NAME=rootfs
ROOTFS_VOL_NAME=rootfs
ROOTFS_UBI_CFG=$ROOTFS_NAME-ubi.cfg
ROOTFS_UBI_IMG=$ROOTFS_NAME-ubi.img

# flash parameters
FLASH_SIZE=4096MiB
FLASH_BLOCK_SIZE=2048KiB
FLASH_PAGE_SIZE=8KiB
FLASH_LOGIC_SIZE=2032KiB

# create /etc/resolv.conf for tmpfs
touch $IMAGE_ROOTFS_DIR/etc/resolv.conf
checkit


cd $LINUX_SRC_DIR/install/bin

# create ubi cfg file
check "$HOSTTOOLS_DIR/genubicfg -f $FLASH_SIZE -b $FLASH_BLOCK_SIZE -p $FLASH_PAGE_SIZE -N $ROOTFS_VOL_NAME -n $ROOTFS_NAME Ali_nand_desc.xml"

# make rootfs image
ROOTFS_UBI_LEB_MSIZE=`cat $IMAGES_DIR/$ROOTFS_UBI_CFG | grep vol_size | awk -F= '{ print $2 }' | awk -FM '{print $1}'`
ROOTFS_UBI_MAX_VOLSIZE=`expr $ROOTFS_UBI_LEB_MSIZE \* 1024 / 2032`
echo "Max rootfs vol_size is $ROOTFS_UBI_MAX_VOLSIZE"

check "$HOSTTOOLS_DIR/mkfs.ubifs -F -r $IMAGE_ROOTFS_DIR -m $FLASH_PAGE_SIZE -e $FLASH_LOGIC_SIZE -c $ROOTFS_UBI_MAX_VOLSIZE -o $ROOTFS_UBI_IMG"
check "$HOSTTOOLS_DIR/ubinize -o $ROOTFS_NAME.img -m $FLASH_PAGE_SIZE -p $FLASH_BLOCK_SIZE $ROOTFS_UBI_CFG"

