#!/bin/bash
set -x
set -e
echo "testing"
USE_RVV="${USE_RVV:-OFF}"
TOOLCHAIN_PATH="${TOOLCHAIN_PATH:-../../build-toolchain-qemu/riscv-clang}"
QEMU_PREFIX_PATH="${QEMU_PREFIX_PATH:-../../build-toolchain-qemu/riscv-qemu/}"

if [ "${USE_RVV}" = "ON" ];then
  QEMU_OPTION="-cpu rv64,zba=true,zbb=true,zbc=true,zbs=true,v=true,vlen=512,elen=64,vext_spec=v1.0,rvv_ma_all_1s=true,rvv_ta_all_1s=true -L ${TOOLCHAIN_PATH}/sysroot"
else
  QEMU_OPTION="-cpu rv64,zba=true,zbb=true,zbc=true,zbs=true -L ${TOOLCHAIN_PATH}/sysroot"
fi

$QEMU_PREFIX_PATH/bin/qemu-riscv64 $QEMU_OPTION $@
