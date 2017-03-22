#!/bin/bash
##
## This file is part of the coreboot project.
##
## Copyright (C) 2009 One Laptop per Child, Association, Inc.
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

# Simple script to dump the factory ACPI DSDT and convert it to C.
# Must be run as root on some systems, and always run on the target machine.

if [ ! iasl ]; then
	echo "Intel ASL Compiler required to recompile DSDT table."
fi

if [ ! -f /proc/acpi/dsdt ]; then
	echo "Cannot find DSDT table, check that your kernel supports and uses ACPI."
fi

cat /proc/acpi/dsdt > dsdt
if [ ! -f dsdt ]; then
	echo "Failed copying DSDT, please check your permissions."
fi

iasl -d -vr -vs dsdt
iasl -tc -vr -vs dsdt.dsl
mv dsdt.hex dsdt.c
echo "Done, cleaning up."
rm -f dsdt dsdt.dsl dsdt.aml dsdt.hex
exit
