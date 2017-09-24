//    Copyright 2017 jmpews
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#ifndef platforms_arch_arm_writer_thumb_h
#define platforms_arch_arm_writer_thumb_h

#include <string.h>

// platforms
#include "instructions.h"
#include "regs-arm.h"
#include "writer-thumb.h"

// hookzz
#include "writer.h"

// zzdeps
#include "hookzz.h"
#include "zzdefs.h"
#include "zzdeps/common/debugbreak.h"
#include "zzdeps/zz.h"

typedef ZzWriter ZzThumbWriter;

typedef enum _ZzThumbMemoryOperation {
    ZZ_THUMB_MEMORY_LOAD,
    ZZ_THUMB_MEMORY_STORE
} ZzThumbMemoryOperation;

// ------- user custom -------

void zz_thumb_writer_put_add_sub_ldr_reg_reg_offset(ZzThumbWriter *self, arm_reg dst_reg,
                                                    arm_reg src_reg, zint32 src_offset);
void zz_thumb_writer_put_add_sub_str_reg_reg_offset(ZzThumbWriter *self, arm_reg src_reg,
                                                    arm_reg dst_reg, zint32 dst_offset);

void zz_thumb_writer_put_ldr_b_reg_address(ZzThumbWriter *self, arm_reg reg, zaddr address);

// ------- architecture default -------

ZzThumbWriter *zz_thumb_writer_new(zpointer data_ptr);
void zz_thumb_writer_init(ZzThumbWriter *self, zpointer data_ptr);
void zz_thumb_writer_reset(ZzThumbWriter *self, zpointer data_ptr);
void zz_thumb_writer_put_nop(ZzThumbWriter *self);
void zz_thumb_writer_put_bytes(ZzThumbWriter *self, zbyte *data, zuint data_size);
void zz_thumb_writer_put_instruction(ZzThumbWriter *self, uint16_t insn);
void zz_thumb_writer_put_b_imm(ZzThumbWriter *self, zuint32 imm);
void zz_thumb_writer_put_bx_reg(ZzThumbWriter *self, arm_reg reg);
void zz_thumb_writer_put_blx_reg(ZzThumbWriter *self, arm_reg reg);
void zz_thumb_writer_put_branch_imm(ZzThumbWriter *self, zuint32 imm, zbool link, zbool thumb);
void zz_thumb_writer_put_bl_imm(ZzThumbWriter *self, zuint32 imm);
void zz_thumb_writer_put_blx_imm(ZzThumbWriter *self, zuint32 imm);
void zz_thumb_writer_put_b_imm32(ZzThumbWriter *self, zuint32 imm);

void zz_thumb_writer_put_ldr_reg_imm(ZzThumbWriter *self, arm_reg reg, zint32 imm);
void zz_thumb_writer_put_ldr_reg_address(ZzThumbWriter *self, arm_reg reg, zaddr address);

static void zz_thumb_writer_put_transfer_reg_reg_offset(ZzThumbWriter *self,
                                                        ZzThumbMemoryOperation operation,
                                                        arm_reg left_reg, arm_reg right_reg,
                                                        zint32 right_offset);
void zz_thumb_writer_put_ldr_reg_reg_offset(ZzThumbWriter *self, arm_reg dst_reg, arm_reg src_reg,
                                            zsize src_offset);
void zz_thumb_writer_put_str_reg_reg_offset(ZzThumbWriter *self, arm_reg src_reg, arm_reg dst_reg,
                                            zsize dst_offset);
void zz_thumb_writer_put_str_reg_reg(ZzThumbWriter *self, arm_reg src_reg, arm_reg dst_reg);
void zz_thumb_writer_put_ldr_reg_reg(ZzThumbWriter *self, arm_reg dst_reg, arm_reg src_reg);
void zz_thumb_writer_put_add_reg_imm(ZzThumbWriter *self, arm_reg dst_reg, zint32 imm);
void zz_thumb_writer_put_sub_reg_imm(ZzThumbWriter *self, arm_reg dst_reg, zint32 imm);
zsize zz_thumb_writer_near_jump_range_size();
#endif