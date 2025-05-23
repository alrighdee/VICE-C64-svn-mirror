/*
 * vic20-generic.h -- VIC20 generic cartridge emulation.
 *
 * Written by
 *  Daniel Kahlin <daniel@kahlin.net>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#ifndef VICE_VIC20_GENERIC_H
#define VICE_VIC20_GENERIC_H

#include <stdio.h>

#include "types.h"

uint8_t generic_ram123_read(uint16_t addr);
void generic_ram123_store(uint16_t addr, uint8_t value);
uint8_t generic_blk1_read(uint16_t addr);
void generic_blk1_store(uint16_t addr, uint8_t value);
uint8_t generic_blk2_read(uint16_t addr);
void generic_blk2_store(uint16_t addr, uint8_t value);
uint8_t generic_blk3_read(uint16_t addr);
void generic_blk3_store(uint16_t addr, uint8_t value);
uint8_t generic_blk5_read(uint16_t addr);
void generic_blk5_store(uint16_t addr, uint8_t value);

void generic_config_setup(uint8_t *rawcart);
int generic_bin_attach(int type, const char *filename);

/* int generic_bin_attach(const char *filename, uint8_t *rawcart); */

int generic_crt_attach(FILE *fd, uint8_t *rawcart);
void generic_detach(void);

int generic_resources_init(void);
void generic_resources_shutdown(void);

struct snapshot_s;

int generic_snapshot_write_module(struct snapshot_s *s);
int generic_snapshot_read_module(struct snapshot_s *s);

/* special case handling need for multiple file generic carts */
int generic_attach_from_resource(int type, const char *filename);
void generic_set_default(void);
void generic_unset_default(void);
const char *generic_get_file_name(uint16_t addr);

#endif
