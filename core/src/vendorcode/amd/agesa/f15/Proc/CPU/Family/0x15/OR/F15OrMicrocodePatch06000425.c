/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD F15Or Microcode patch.
 *
 * F15Or Microcode Patch rev 06000425 for 6010 or equivalent.
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGESA
 * @e sub-project:  CPU/FAMILY/0x15/Or
 * @e \$Revision: 53746 $   @e \$Date: 2011-05-24 23:08:53 -0600 (Tue, 24 May 2011) $
 */
/*****************************************************************************
 *
 * Copyright (C) 2012 Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 ***************************************************************************/



/*----------------------------------------------------------------------------------------
 *                             M O D U L E S    U S E D
 *----------------------------------------------------------------------------------------
 */
#include "AGESA.h"
#include "Ids.h"
#include "cpuRegisters.h"
#include "cpuEarlyInit.h"
CODE_GROUP (G3_DXE)
RDATA_GROUP (G3_DXE)

/*----------------------------------------------------------------------------------------
 *                   D E F I N I T I O N S    A N D    M A C R O S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                  T Y P E D E F S     A N D     S T R U C T U R E S
 *----------------------------------------------------------------------------------------
 */


// Encrypted Patch code 06000425 for 6010 and equivalent
CONST UINT8 ROMDATA CpuF15OrMicrocodePatch06000425 [IDS_PAD_4K] =
{
  0x11,
  0x20,
  0x08,
  0x04,
  0x25,
  0x04,
  0x00,
  0x06,
  0x02,
  0x80,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x10,
  0x60,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x55,
  0xbf,
  0xbd,
  0x55,
  0xea,
  0x96,
  0xd6,
  0xed,
  0x1a,
  0x82,
  0xda,
  0x4a,
  0xdc,
  0xc0,
  0x8a,
  0x21,
  0x02,
  0x4c,
  0x0f,
  0x68,
  0xc4,
  0x31,
  0x74,
  0xa8,
  0x32,
  0xfc,
  0xb3,
  0xad,
  0xbc,
  0x51,
  0x53,
  0x89,
  0x65,
  0xc5,
  0x49,
  0x28,
  0x9f,
  0x9c,
  0xe4,
  0xb8,
  0x90,
  0x02,
  0x27,
  0x30,
  0x5f,
  0x19,
  0xba,
  0x72,
  0x0b,
  0x8c,
  0x78,
  0xcb,
  0x2e,
  0x00,
  0x7c,
  0x2b,
  0x9b,
  0x0a,
  0xa2,
  0xd2,
  0x20,
  0x8b,
  0x6c,
  0xc0,
  0xce,
  0xae,
  0x0e,
  0x8f,
  0xe7,
  0xaf,
  0xc7,
  0x5d,
  0xf9,
  0xcb,
  0x35,
  0x79,
  0xc0,
  0x1e,
  0x33,
  0x5f,
  0x05,
  0x95,
  0x0c,
  0x6f,
  0x43,
  0xc7,
  0x85,
  0x52,
  0xd9,
  0x06,
  0x58,
  0xec,
  0xe7,
  0xdb,
  0x6d,
  0xba,
  0xb4,
  0x5b,
  0x32,
  0xeb,
  0xe4,
  0xb2,
  0xd5,
  0x77,
  0x1c,
  0xe6,
  0x84,
  0xaf,
  0x2c,
  0x12,
  0x18,
  0xf7,
  0x3c,
  0xbf,
  0xa8,
  0x90,
  0xcb,
  0x40,
  0x46,
  0xee,
  0x48,
  0x0c,
  0x53,
  0x80,
  0x9a,
  0x94,
  0x4d,
  0x73,
  0x3e,
  0x2f,
  0x98,
  0xc0,
  0x25,
  0x75,
  0xbd,
  0xe8,
  0x99,
  0x38,
  0xad,
  0xfa,
  0xda,
  0xcf,
  0x3f,
  0xe5,
  0x4b,
  0x38,
  0x76,
  0x3b,
  0xe5,
  0xa2,
  0xef,
  0x38,
  0x11,
  0xbd,
  0x8d,
  0x84,
  0x75,
  0x88,
  0x72,
  0xdd,
  0xd4,
  0xcd,
  0x85,
  0xcd,
  0xd1,
  0xc6,
  0xae,
  0xd1,
  0xc2,
  0xfa,
  0xb1,
  0xc4,
  0xc2,
  0xc9,
  0x35,
  0xc4,
  0xc1,
  0x3a,
  0xbe,
  0xcc,
  0x08,
  0x94,
  0xba,
  0x52,
  0x98,
  0xd6,
  0xd4,
  0x70,
  0x84,
  0x48,
  0x3b,
  0x9d,
  0xfd,
  0x24,
  0x81,
  0x50,
  0xbf,
  0xe2,
  0x2b,
  0xf5,
  0x5f,
  0x3b,
  0x99,
  0x76,
  0x98,
  0xc2,
  0xf2,
  0x36,
  0x1c,
  0x64,
  0xea,
  0xdc,
  0xd7,
  0x10,
  0x0f,
  0x76,
  0xcc,
  0x2c,
  0x9e,
  0x23,
  0x45,
  0x8b,
  0x0f,
  0x4e,
  0x4b,
  0x34,
  0x89,
  0x7d,
  0x5b,
  0x21,
  0x8a,
  0x25,
  0x5b,
  0x69,
  0xe3,
  0xde,
  0xb4,
  0xa9,
  0xf7,
  0x48,
  0x9a,
  0xea,
  0x40,
  0x3c,
  0x9c,
  0x41,
  0x8f,
  0x69,
  0x3c,
  0x10,
  0x6e,
  0xf8,
  0x11,
  0x7c,
  0x73,
  0xe9,
  0x96,
  0xed,
  0x90,
  0x9e,
  0x07,
  0x45,
  0x65,
  0x6b,
  0x68,
  0x5d,
  0x9d,
  0x72,
  0xdb,
  0xb2,
  0xbc,
  0x81,
  0x65,
  0xeb,
  0x84,
  0x33,
  0xdc,
  0xe9,
  0x0f,
  0xd5,
  0x0e,
  0xc8,
  0x5e,
  0x14,
  0x80,
  0x64,
  0x0b,
  0x9e,
  0x46,
  0xde,
  0xbe,
  0x9e,
  0x12,
  0xac,
  0x50,
  0xc4,
  0x33,
  0xce,
  0xf7,
  0xba,
  0xc7,
  0xdf,
  0x43,
  0x09,
  0x9b,
  0xa3,
  0x21,
  0xc5,
  0xe0,
  0x48,
  0xe6,
  0x19,
  0xd8,
  0xa6,
  0x6f,
  0x29,
  0xb3,
  0x0e,
  0xc4,
  0xc6,
  0xe6,
  0xdd,
  0x96,
  0xab,
  0x54,
  0xb9,
  0x80,
  0x73,
  0x61,
  0xe6,
  0x85,
  0x9b,
  0xe5,
  0x00,
  0xfa,
  0xe8,
  0x04,
  0xe5,
  0x33,
  0xfe,
  0x7e,
  0xae,
  0xe7,
  0x55,
  0x53,
  0xe4,
  0x63,
  0x6a,
  0xfa,
  0x76,
  0x9e,
  0x28,
  0x88,
  0xb8,
  0xc6,
  0x75,
  0x4c,
  0xa0,
  0x9f,
  0x01,
  0xf9,
  0x9e,
  0x89,
  0xf6,
  0xce,
  0x91,
  0xbf,
  0x4e,
  0xfe,
  0xbd,
  0x52,
  0xea,
  0xfe,
  0x06,
  0xc5,
  0xad,
  0xcf,
  0xb8,
  0xa0,
  0xec,
  0x78,
  0x4b,
  0xec,
  0x3b,
  0x80,
  0xf4,
  0x84,
  0xbe,
  0x69,
  0x5f,
  0x5e,
  0x7a,
  0x13,
  0x89,
  0x95,
  0x91,
  0x07,
  0x56,
  0xdb,
  0x5d,
  0xfa,
  0x10,
  0xfc,
  0x5d,
  0x99,
  0xb5,
  0xe8,
  0x59,
  0x96,
  0x15,
  0x56,
  0xe6,
  0x8d,
  0x06,
  0x7f,
  0x5e,
  0x1b,
  0xc6,
  0x4c,
  0xa6,
  0x73,
  0x28,
  0x6a,
  0xa5,
  0xf3,
  0xc1,
  0x45,
  0x86,
  0x8d,
  0x4a,
  0x88,
  0x94,
  0x4d,
  0x7f,
  0x15,
  0xe8,
  0x9f,
  0x19,
  0x25,
  0x86,
  0xdc,
  0x6b,
  0xbd,
  0x5d,
  0xe0,
  0x76,
  0xa5,
  0x2e,
  0x58,
  0xc2,
  0xb3,
  0xed,
  0x2d,
  0x7f,
  0xb5,
  0x83,
  0xf1,
  0xd5,
  0x79,
  0xb5,
  0x5b,
  0x55,
  0x94,
  0x18,
  0x44,
  0x43,
  0x42,
  0xe4,
  0xe5,
  0xbf,
  0x59,
  0xa2,
  0x33,
  0x05,
  0x16,
  0x2d,
  0x9e,
  0x01,
  0x12,
  0xd3,
  0x3d,
  0x29,
  0x97,
  0xaa,
  0x9c,
  0x63,
  0x17,
  0x5c,
  0x39,
  0xef,
  0xe9,
  0xa5,
  0x70,
  0x24,
  0xb7,
  0x31,
  0x97,
  0xab,
  0x18,
  0xae,
  0x9d,
  0xa0,
  0x12,
  0xde,
  0x36,
  0x7e,
  0x1d,
  0x91,
  0xbf,
  0x77,
  0x14,
  0xdf,
  0x6b,
  0xc6,
  0xb6,
  0x11,
  0x04,
  0x25,
  0xef,
  0x52,
  0x0b,
  0x42,
  0xff,
  0xc4,
  0x6b,
  0x19,
  0x44,
  0xcd,
  0xbd,
  0x38,
  0x02,
  0xa2,
  0x47,
  0x8f,
  0x95,
  0x37,
  0x9d,
  0x5b,
  0x32,
  0x37,
  0x08,
  0x4e,
  0x03,
  0x5f,
  0x18,
  0x03,
  0xa9,
  0xbe,
  0xe1,
  0x70,
  0x44,
  0xe0,
  0xc7,
  0xc6,
  0x76,
  0x19,
  0xe5,
  0x08,
  0x82,
  0xb2,
  0x07,
  0x96,
  0xa7,
  0xb5,
  0x07,
  0xfd,
  0x67,
  0x46,
  0x9d,
  0x87,
  0x77,
  0x9b,
  0xd1,
  0xaa,
  0x4d,
  0xc3,
  0x12,
  0x22,
  0xfd,
  0x61,
  0xee,
  0xe1,
  0xb6,
  0x71,
  0x83,
  0xc9,
  0x0d,
  0x57,
  0xf1,
  0xed,
  0xc2,
  0xdf,
  0xeb,
  0x3a,
  0x2a,
  0xf6,
  0xb7,
  0x24,
  0xac,
  0x1b,
  0x89,
  0xc8,
  0xdc,
  0x69,
  0x15,
  0xc4,
  0x20,
  0xe9,
  0x43,
  0x32,
  0xde,
  0xde,
  0xa8,
  0x81,
  0x1c,
  0x10,
  0x8f,
  0xf8,
  0x04,
  0xca,
  0x1f,
  0x98,
  0x13,
  0x9b,
  0xa5,
  0xa6,
  0x02,
  0x36,
  0xc7,
  0xd3,
  0x6c,
  0x49,
  0x60,
  0x37,
  0x25,
  0x9a,
  0xe0,
  0xea,
  0xf4,
  0xfd,
  0x93,
  0xdb,
  0xd8,
  0x78,
  0xb7,
  0xfe,
  0x40,
  0x74,
  0x99,
  0x80,
  0x9a,
  0x90,
  0x83,
  0x28,
  0x6d,
  0x01,
  0x61,
  0xd4,
  0x4f,
  0x1d,
  0x89,
  0x6e,
  0x95,
  0x77,
  0x24,
  0xd2,
  0xf1,
  0xbb,
  0x6f,
  0xd9,
  0xad,
  0x0f,
  0xde,
  0x63,
  0xf7,
  0xfa,
  0x22,
  0x6b,
  0x91,
  0x1e,
  0xf9,
  0xf9,
  0x01,
  0x51,
  0xde,
  0x79,
  0xec,
  0x9f,
  0x3f,
  0x28,
  0xdf,
  0x82,
  0x84,
  0xbd,
  0xa3,
  0x5e,
  0xb2,
  0xf8,
  0x8b,
  0x75,
  0xdc,
  0xf3,
  0x88,
  0x78,
  0x50,
  0xb6,
  0x87,
  0xa7,
  0x37,
  0x95,
  0xcb,
  0xb8,
  0xb3,
  0xa4,
  0x58,
  0xe2,
  0xf7,
  0x2c,
  0x95,
  0x9c,
  0x69,
  0x2e,
  0xe1,
  0xbd,
  0xc4,
  0x87,
  0x19,
  0x45,
  0x9b,
  0x3f,
  0x7e,
  0x40,
  0x8b,
  0xd4,
  0x40,
  0x1b,
  0x28,
  0xb2,
  0x61,
  0x6d,
  0x96,
  0x6d,
  0x56,
  0xae,
  0xec,
  0x06,
  0xe6,
  0x61,
  0x06,
  0x3a,
  0x0f,
  0x10,
  0x49,
  0xbd,
  0xd0,
  0x8f,
  0xd9,
  0xd3,
  0xa0,
  0x3c,
  0x1d,
  0x0d,
  0xef,
  0x64,
  0xb5,
  0xd4,
  0x08,
  0xa6,
  0x37,
  0x55,
  0x53,
  0xaa,
  0x98,
  0x94,
  0x41,
  0x7d,
  0x48,
  0x13,
  0x36,
  0xaa,
  0x3d,
  0x12,
  0xeb,
  0x30,
  0x91,
  0xaa,
  0x40,
  0x63,
  0x23,
  0xe5,
  0xc2,
  0x83,
  0x1e,
  0xaa,
  0xe1,
  0x78,
  0xd4,
  0x9d,
  0x54,
  0xdc,
  0xb8,
  0xf3,
  0xd8,
  0x24,
  0x5e,
  0xe8,
  0x5b,
  0xcb,
  0x46,
  0x74,
  0x09,
  0x00,
  0xb2,
  0x75,
  0x9a,
  0xcf,
  0x36,
  0x0b,
  0xb6,
  0xfe,
  0xb4,
  0x5d,
  0x1d,
  0xb5,
  0x87,
  0x60,
  0xeb,
  0xba,
  0xba,
  0xe0,
  0x2e,
  0xb8,
  0xa5,
  0x3d,
  0x5b,
  0x4c,
  0xca,
  0x2c,
  0x16,
  0x19,
  0x62,
  0x1e,
  0xa2,
  0xbf,
  0xa9,
  0x68,
  0xde,
  0xbe,
  0x1b,
  0x2c,
  0x61,
  0x8d,
  0x52,
  0x06,
  0xb0,
  0x58,
  0xad,
  0x81,
  0xa6,
  0x1b,
  0x04,
  0x02,
  0xfa,
  0x37,
  0xf1,
  0xd3,
  0x13,
  0xed,
  0x37,
  0x88,
  0x6b,
  0x1f,
  0xc8,
  0x5c,
  0x3c,
  0x41,
  0x1e,
  0x84,
  0x73,
  0xef,
  0xc4,
  0x41,
  0x13,
  0xcf,
  0xae,
  0xcf,
  0xbd,
  0x10,
  0xf7,
  0x5a,
  0x67,
  0x8d,
  0x48,
  0xc0,
  0xae,
  0x3a,
  0x68,
  0xc8,
  0x38,
  0x37,
  0x3c,
  0x22,
  0x9c,
  0x0a,
  0x73,
  0xdc,
  0xb4,
  0x8e,
  0xce,
  0x74,
  0x76,
  0x0b,
  0x92,
  0x32,
  0x99,
  0x92,
  0xd9,
  0xb9,
  0xc6,
  0x3f,
  0x19,
  0xed,
  0xfe,
  0xfd,
  0x8b,
  0xf4,
  0xb9,
  0x86,
  0x92,
  0x39,
  0x40,
  0x87,
  0x53,
  0xdf,
  0x1b,
  0xde,
  0x13,
  0xe5,
  0x4a,
  0x81,
  0x8f,
  0x8e,
  0xc5,
  0x9b,
  0xcd,
  0x63,
  0x9f,
  0x46,
  0x71,
  0x01,
  0x4f,
  0xa3,
  0xa2,
  0xef,
  0x32,
  0x54,
  0x04,
  0x1f,
  0x7e,
  0x6b,
  0xbe,
  0x84,
  0x3c,
  0x49,
  0x5c,
  0x5b,
  0xd7,
  0x7c,
  0x93,
  0x2f,
  0x20,
  0x74,
  0xcc,
  0x40,
  0xf2,
  0x21,
  0x87,
  0x11,
  0xc2,
  0xba,
  0xfb,
  0x20,
  0xdb,
  0xd6,
  0xd9,
  0x7c,
  0xce,
  0xee,
  0x68,
  0xa3,
  0xe7,
  0x1e,
  0x86,
  0x4a,
  0x94,
  0x2f,
  0x50,
  0x8a,
  0x2e,
  0xe1,
  0x25,
  0xaa,
  0x8c,
  0xf1,
  0x87,
  0x7c,
  0xc3,
  0x31,
  0xcd,
  0x4c,
  0xf1,
  0x24,
  0xd7,
  0xf2,
  0x86,
  0xfb,
  0x79,
  0x67,
  0x96,
  0x3e,
  0x6a,
  0x69,
  0x6c,
  0xaf,
  0x44,
  0x18,
  0xe0,
  0xf5,
  0x16,
  0x5f,
  0x6d,
  0x64,
  0x3f,
  0x7d,
  0x8e,
  0x88,
  0x51,
  0x3b,
  0xad,
  0xf5,
  0x9e,
  0x56,
  0x58,
  0x37,
  0xd4,
  0x70,
  0x21,
  0xb5,
  0xd3,
  0x1e,
  0x62,
  0xda,
  0x5b,
  0x01,
  0x82,
  0xd8,
  0xff,
  0xaf,
  0x57,
  0xd4,
  0x74,
  0x0e,
  0xa4,
  0x1b,
  0xf6,
  0xe2,
  0x0d,
  0x71,
  0xae,
  0xc6,
  0xed,
  0x55,
  0x46,
  0x30,
  0xab,
  0xab,
  0xa9,
  0x1d,
  0x01,
  0xb9,
  0x93,
  0x7d,
  0x33,
  0x11,
  0x96,
  0x19,
  0xbb,
  0x0c,
  0x61,
  0xe6,
  0x7c,
  0xfa,
  0x26,
  0x10,
  0x5a,
  0x0c,
  0x19,
  0xd4,
  0x5f,
  0x8e,
  0xd5,
  0xaf,
  0x40,
  0x1d,
  0xa3,
  0xff,
  0x20,
  0x15,
  0x14,
  0xab,
  0x06,
  0x5b,
  0x20,
  0xb2,
  0xa8,
  0xc8,
  0x3b,
  0xa2,
  0xd6,
  0x29,
  0x78,
  0x85,
  0x1f,
  0xbe,
  0x91,
  0x2c,
  0x71,
  0x27,
  0xb6,
  0xcf,
  0x7d,
  0xb3,
  0x4d,
  0x5b,
  0x18,
  0x88,
  0x66,
  0x31,
  0x79,
  0xc1,
  0xcf,
  0x02,
  0x87,
  0x33,
  0x78,
  0x03,
  0x20,
  0x88,
  0xff,
  0x30,
  0x94,
  0xa6,
  0xc5,
  0x76,
  0x38,
  0x54,
  0xc4,
  0x62,
  0x4d,
  0x51,
  0x54,
  0xfb,
  0xce,
  0xa8,
  0x1b,
  0x95,
  0xd4,
  0xfa,
  0xb1,
  0x7f,
  0x83,
  0xd2,
  0x2b,
  0xcb,
  0x9b,
  0xd4,
  0x31,
  0x0f,
  0x37,
  0xff,
  0x1a,
  0x28,
  0x80,
  0x2a,
  0x2d,
  0x49,
  0x0e,
  0x3f,
  0xe8,
  0x9e,
  0x18,
  0x90,
  0xd3,
  0xef,
  0xbc,
  0x43,
  0xd3,
  0x7a,
  0x5e,
  0x8d,
  0x58,
  0xb3,
  0xc1,
  0xa2,
  0x53,
  0xe9,
  0x18,
  0xc2,
  0x4b,
  0xda,
  0x9f,
  0x62,
  0x3d,
  0xa2,
  0x2c,
  0x1f,
  0xc1,
  0x5b,
  0x87,
  0xa2,
  0x68,
  0xb7,
  0xc2,
  0xd5,
  0x1b,
  0x36,
  0xa5,
  0xf1,
  0xef,
  0x17,
  0x5f,
  0x59,
  0xec,
  0xc5,
  0x50,
  0x0a,
  0x26,
  0xde,
  0x51,
  0x36,
  0x64,
  0xbe,
  0xd5,
  0x97,
  0x77,
  0xc0,
  0x66,
  0x5b,
  0x55,
  0xb8,
  0x13,
  0xfd,
  0x17,
  0x0f,
  0xf1,
  0x52,
  0xb8,
  0xbb,
  0x0e,
  0xf9,
  0xcf,
  0x44,
  0xdd,
  0xb8,
  0x2d,
  0xdd,
  0xf0,
  0xd1,
  0x9c,
  0x54,
  0xa7,
  0x00,
  0x38,
  0x5e,
  0x9c,
  0x20,
  0x60,
  0x3e,
  0x1c,
  0x69,
  0x79,
  0xa6,
  0x9a,
  0x7a,
  0xe7,
  0x16,
  0xa2,
  0x26,
  0x9b,
  0x0c,
  0x1b,
  0x62,
  0x92,
  0xa0,
  0x82,
  0x6f,
  0x7a,
  0xe2,
  0x9a,
  0xc8,
  0xe0,
  0xac,
  0xb5,
  0x62,
  0xfc,
  0x39,
  0x17,
  0xd8,
  0x95,
  0x39,
  0xb4,
  0x59,
  0x4b,
  0x07,
  0x56,
  0x70,
  0xd7,
  0x5e,
  0x4c,
  0x06,
  0xca,
  0x12,
  0xd0,
  0x85,
  0xef,
  0xd0,
  0x4c,
  0x12,
  0xf1,
  0x3b,
  0xdf,
  0xd7,
  0x2f,
  0x7d,
  0xac,
  0xca,
  0x30,
  0x47,
  0x00,
  0x40,
  0x3c,
  0xa4,
  0xce,
  0xab,
  0xf0,
  0x96,
  0x0b,
  0x2d,
  0x07,
  0x5c,
  0x83,
  0x80,
  0x54,
  0x59,
  0x65,
  0x09,
  0x57,
  0x70,
  0x8d,
  0x25,
  0x8d,
  0x6e,
  0x4a,
  0x77,
  0x5e,
  0x30,
  0xe0,
  0xc4,
  0x0c,
  0xb7,
  0xf9,
  0x51,
  0xba,
  0x0c,
  0x8f,
  0x6f,
  0x9a,
  0xe1,
  0xce,
  0x5a,
  0x06,
  0xd7,
  0x16,
  0x34,
  0x9b,
  0x50,
  0x91,
  0x34,
  0x0c,
  0x34,
  0xcb,
  0xb7,
  0x73,
  0xc8,
  0x88,
  0x34,
  0xaf,
  0xb6,
  0x4d,
  0x1a,
  0xfb,
  0x2c,
  0x9a,
  0xb1,
  0xbf,
  0xda,
  0xb2,
  0x88,
  0x4a,
  0x0e,
  0x0b,
  0x96,
  0xc2,
  0x4b,
  0x76,
  0xd4,
  0x64,
  0x54,
  0x8d,
  0x82,
  0xe5,
  0xda,
  0xc8,
  0xb5,
  0x4f,
  0xb3,
  0xb6,
  0x3d,
  0xa5,
  0x47,
  0x41,
  0xde,
  0xfe,
  0x11,
  0x36,
  0x6a,
  0x6f,
  0xad,
  0x76,
  0xe5,
  0xab,
  0x4c,
  0x56,
  0x04,
  0xc8,
  0xb4,
  0x2f,
  0x9f,
  0x02,
  0x12,
  0x5f,
  0x5c,
  0x1c,
  0xce,
  0x20,
  0x77,
  0x45,
  0x63,
  0x20,
  0x04,
  0xb0,
  0x1b,
  0xdf,
  0xaf,
  0x60,
  0x36,
  0x6a,
  0x3d,
  0x54,
  0x94,
  0x02,
  0xfa,
  0x40,
  0xa7,
  0xc3,
  0xa1,
  0xb7,
  0xad,
  0x92,
  0xcc,
  0x9d,
  0xaa,
  0x86,
  0xd6,
  0x82,
  0xd7,
  0xd2,
  0x48,
  0x34,
  0x87,
  0xe9,
  0x4b,
  0x0d,
  0xc4,
  0x7a,
  0x5b,
  0x3c,
  0x6d,
  0xa7,
  0x30,
  0x0c,
  0x04,
  0x84,
  0xe0,
  0x44,
  0xeb,
  0x58,
  0x0c,
  0xf9,
  0xd1,
  0xf3,
  0x6f,
  0xe1,
  0xfb,
  0x65,
  0x04,
  0x0f,
  0xbd,
  0x74,
  0xa6,
  0x54,
  0xe8,
  0x4c,
  0x30,
  0x96,
  0x3a,
  0x95,
  0x50,
  0xaf,
  0x2b,
  0x93,
  0x88,
  0x20,
  0x19,
  0x0f,
  0x74,
  0x11,
  0xe8,
  0x20,
  0x70,
  0x10,
  0x1c,
  0x2f,
  0x7a,
  0x6b,
  0xb5,
  0x96,
  0x20,
  0xc6,
  0xf8,
  0x87,
  0x4c,
  0xdd,
  0xdc,
  0x07,
  0x5f,
  0xed,
  0x49,
  0x5c,
  0x3d,
  0xdf,
  0x84,
  0x92,
  0xe7,
  0xca,
  0x2f,
  0x3e,
  0xba,
  0x07,
  0x59,
  0x10,
  0x7a,
  0xbb,
  0x6d,
  0xb1,
  0x61,
  0x72,
  0x77,
  0xa0,
  0xc9,
  0x93,
  0xb9,
  0x61,
  0xe7,
  0xf9,
  0xc4,
  0x81,
  0x0f,
  0x9a,
  0x0e,
  0x2e,
  0x04,
  0x35,
  0x90,
  0x09,
  0x5e,
  0xfb,
  0x05,
  0x03,
  0x65,
  0x80,
  0x1b,
  0xa5,
  0x98,
  0x1b,
  0x45,
  0x60,
  0x94,
  0x03,
  0x1b,
  0x42,
  0x45,
  0x3d,
  0xe6,
  0x6c,
  0x58,
  0x9f,
  0x62,
  0xc8,
  0xf0,
  0x59,
  0xa0,
  0x8b,
  0xf6,
  0xba,
  0xe6,
  0xdd,
  0xb0,
  0xc1,
  0x13,
  0x16,
  0x43,
  0x6c,
  0x7d,
  0x55,
  0xf8,
  0xc8,
  0xae,
  0xe5,
  0x11,
  0x22,
  0xa1,
  0xab,
  0xcb,
  0xc4,
  0x4d,
  0xa0,
  0x69,
  0xa4,
  0x7b,
  0x24,
  0x68,
  0xcb,
  0x98,
  0xc3,
  0x41,
  0x93,
  0x75,
  0x10,
  0x89,
  0xa5,
  0x13,
  0xe5,
  0xe7,
  0x44,
  0x87,
  0x83,
  0x33,
  0x6b,
  0xfb,
  0x13,
  0x21,
  0x51,
  0x02,
  0x76,
  0x4d,
  0x46,
  0x2c,
  0x14,
  0x40,
  0x06,
  0x2c,
  0x38,
  0x0e,
  0x3e,
  0x6c,
  0xc7,
  0xb9,
  0x26,
  0xee,
  0xe5,
  0x15,
  0xdc,
  0x60,
  0x9d,
  0x5f,
  0xf2,
  0xca,
  0x97,
  0xe3,
  0xcc,
  0x68,
  0xcd,
  0x22,
  0x86,
  0x86,
  0x94,
  0x80,
  0xbb,
  0xb9,
  0x27,
  0x55,
  0xfc,
  0x0d,
  0x88,
  0x8a,
  0xb4,
  0x9c,
  0x61,
  0x3f,
  0xa5,
  0x0a,
  0x14,
  0xbf,
  0xbc,
  0xc4,
  0x51,
  0x61,
  0x2c,
  0x55,
  0x20,
  0x2a,
  0x31,
  0x48,
  0x89,
  0xa3,
  0x2f,
  0x90,
  0xc5,
  0xc5,
  0xa6,
  0xb1,
  0x52,
  0x29,
  0x08,
  0x2f,
  0x08,
  0x92,
  0x35,
  0xf3,
  0xd3,
  0x20,
  0x83,
  0xe1,
  0x1d,
  0xdc,
  0x15,
  0x18,
  0x84,
  0xb3,
  0x77,
  0x18,
  0xbd,
  0xf8,
  0x96,
  0x9d,
  0x74,
  0x97,
  0x50,
  0xee,
  0xa9,
  0xbe,
  0xa1,
  0x37,
  0xdb,
  0x71,
  0x38,
  0x97,
  0xff,
  0x62,
  0x87,
  0x40,
  0x7c,
  0xb1,
  0x7f,
  0x56,
  0x4e,
  0x05,
  0xa3,
  0x03,
  0x4f,
  0x52,
  0x2e,
  0xe4,
  0xf2,
  0x47,
  0xcc,
  0xe4,
  0x4b,
  0x58,
  0x42,
  0xee,
  0x3a,
  0x1e,
  0x79,
  0xe9,
  0xd6,
  0x16,
  0x81,
  0x6d,
  0xb0,
  0x08,
  0x9e,
  0x8e,
  0x5a,
  0x70,
  0xcd,
  0x9b,
  0xd5,
  0xa2,
  0xd2,
  0xdd,
  0x0f,
  0xa3,
  0xa2,
  0xbe,
  0xbb,
  0x76,
  0xfd,
  0x5b,
  0x5c,
  0x0c,
  0x76,
  0xe9,
  0x73,
  0xc4,
  0xc8,
  0xbd,
  0x4f,
  0xb8,
  0x7a,
  0xe6,
  0x87,
  0x1e,
  0xda,
  0x90,
  0x37,
  0x3b,
  0xca,
  0xcf,
  0xf2,
  0x96,
  0x83,
  0xbe,
  0xe4,
  0xc8,
  0x8a,
  0x1a,
  0xaa,
  0xed,
  0xc0,
  0xd2,
  0x47,
  0x2e,
  0x21,
  0xfc,
  0xf4,
  0x92,
  0xca,
  0xd1,
  0x66,
  0x93,
  0x1f,
  0x33,
  0x5d,
  0xa5,
  0xe0,
  0x58,
  0xcd,
  0x01,
  0xe0,
  0x32,
  0x08,
  0xaf,
  0x73,
  0x3a,
  0x35,
  0xf3,
  0x16,
  0x70,
  0x7c,
  0xda,
  0x61,
  0x4f,
  0xe3,
  0xd8,
  0x34,
  0x31,
  0x28,
  0x26,
  0xc9,
  0xe2,
  0x8b,
  0xf5,
  0x63,
  0x1a,
  0x40,
  0x46,
  0xb3,
  0x46,
  0x88,
  0x77,
  0x30,
  0x71,
  0xf0,
  0x11,
  0x6c,
  0x23,
  0x68,
  0x90,
  0x79,
  0x47,
  0x56,
  0xee,
  0xec,
  0x01,
  0xc2,
  0x6f,
  0x2f,
  0x8d,
  0xd2,
  0x32,
  0xa0,
  0x54,
  0x26,
  0x4a,
  0x41,
  0x12,
  0xfb,
  0x18,
  0xce,
  0x53,
  0x8e,
  0xb5,
  0x39,
  0x48,
  0x64,
  0x9a,
  0x03,
  0x01,
  0x0c,
  0x66,
  0xd3,
  0xee,
  0xdc,
  0x5a,
  0x79,
  0xa1,
  0x71,
  0xdc,
  0x82,
  0x69,
  0xec,
  0x10,
  0xd4,
  0xc7,
  0x91,
  0x24,
  0x25,
  0xb8,
  0x2b,
  0x72,
  0x75,
  0x87,
  0x4f,
  0xf4,
  0x74,
  0x60,
  0xa0,
  0x67,
  0xb2,
  0x99,
  0x02,
  0x93,
  0x07,
  0x82,
  0x86,
  0xed,
  0xd6,
  0x3a,
  0xc3,
  0xcd,
  0xe8,
  0x87,
  0x5a,
  0xfa,
  0x56,
  0xe9,
  0x1c,
  0xa8,
  0x61,
  0xbb,
  0xc1,
  0xbb,
  0x06,
  0xd8,
  0xda,
  0x12,
  0xe3,
  0x4c,
  0xd2,
  0x12,
  0xe8,
  0xeb,
  0x3e,
  0x28,
  0x56,
  0xc7,
  0x1d,
  0x44,
  0x02,
  0xc3,
  0xdf,
  0x5f,
  0xa6,
  0x70,
  0x48,
  0xea,
  0xea,
  0x78,
  0xa5,
  0x53,
  0x83,
  0x98,
  0x61,
  0x45,
  0x0e,
  0x00,
  0xfd,
  0x72,
  0x5e,
  0x5b,
  0x04,
  0x48,
  0x60,
  0x65,
  0x15,
  0xa7,
  0x94,
  0x88,
  0x7c,
  0x0d,
  0xbc,
  0x70,
  0x68,
  0xbf,
  0x3b,
  0xcb,
  0xaa,
  0x96,
  0x0c,
  0x2a,
  0xb0,
  0xe0,
  0x0b,
  0x9a,
  0x06,
  0x1f,
  0x8d,
  0x21,
  0x95,
  0xe0,
  0xab,
  0x33,
  0xaf,
  0xf2,
  0x76,
  0xfe,
  0xb1,
  0x13,
  0x2c,
  0xee,
  0xdf,
  0x4e,
  0x62,
  0x6b,
  0xd2,
  0x8c,
  0x63,
  0xab,
  0xcd,
  0x9d,
  0xc8,
  0x41,
  0x0f,
  0xd2,
  0x5f,
  0x78,
  0xc8,
  0xdc,
  0x29,
  0xe7,
  0xb3,
  0x7f,
  0xae,
  0x50,
  0xe1,
  0xcf,
  0xef,
  0xa2,
  0x27,
  0x6f,
  0x8a,
  0x82,
  0x83,
  0x18,
  0x4d,
  0xb3,
  0xb1,
  0x89,
  0x54,
  0xf1,
  0x62,
  0xf7,
  0xc6,
  0x00,
  0x0a,
  0x8d,
  0xd9,
  0x17,
  0xde,
  0xdc,
  0xac,
  0x02,
  0xad,
  0xcc,
  0x7d,
  0x03,
  0x52,
  0x67,
  0xb6,
  0x60,
  0xd1,
  0x1e,
  0x63,
  0xf0,
  0xe5,
  0x92,
  0xb5,
  0xe9,
  0xf2,
  0xa3,
  0xf8,
  0xc1,
  0x5d,
  0x0b,
  0x30,
  0x63,
  0x83,
  0x6b,
  0x6a,
  0x68,
  0x65,
  0x39,
  0x23,
  0x65,
  0x28,
  0x67,
  0x4c,
  0xbf,
  0x01,
  0xd6,
  0x44,
  0x57,
  0xc5,
  0x58,
  0x9b,
  0x19,
  0xbd,
  0x4b,
  0x35,
  0xef,
  0x91,
  0x86,
  0xb1,
  0xe0,
  0xb2,
  0x90,
  0xb0,
  0x31,
  0x03,
  0xe9,
  0x07,
  0x9c,
  0x61,
  0x35,
  0xe8,
  0x02,
  0xd3,
  0x53,
  0x00,
  0xa3,
  0x5e,
  0xa4,
  0xf0,
  0xcd,
  0x4e,
  0xfa,
  0xa7,
  0x76,
  0x1b,
  0xd8,
  0x70,
  0x45,
  0x1f,
  0xca,
  0xc0,
  0xe9,
  0xb9,
  0x02,
  0x3c,
  0x2c,
  0x17,
  0x07,
  0xe8,
  0x8b,
  0x80,
  0x43,
  0x96,
  0x61,
  0xa4,
  0x4c,
  0x11,
  0x17,
  0xe1,
  0xab,
  0x70,
  0xfe,
  0x14,
  0xe7,
  0x3d,
  0xdc,
  0x71,
  0xc0,
  0x63,
  0x96,
  0x78,
  0x7b,
  0x4c,
  0xb4,
  0xee,
  0x56,
  0x34,
  0x7f,
  0x15,
  0xff,
  0xb5,
  0xe5,
  0x65,
  0x36,
  0xdf,
  0x56,
  0x0b,
  0x32,
  0x6a,
  0xca,
  0x38,
  0x54,
  0x99,
  0xe7,
  0xd0,
  0x30,
  0x0b,
  0x9d,
  0x8c,
  0x7d,
  0x81,
  0xd5,
  0x4b,
  0x91,
  0x5f,
  0x24,
  0x7c,
  0xe8,
  0x9b,
  0x23,
  0x58,
  0xd1,
  0x10,
  0x45,
  0x19,
  0xce,
  0x32,
  0x7a,
  0x1e,
  0x8a,
  0xba,
  0x58,
  0x55,
  0x2a,
  0x46,
  0x4e,
  0xcf,
  0x82,
  0x5b,
  0xfe,
  0xed,
  0x83,
  0xbc,
  0xf7,
  0xf4,
  0x43,
  0x01,
  0x6d,
  0xaa,
  0x22,
  0xf3,
  0x1e,
  0x2a,
  0x4b,
  0x26,
  0xc7,
  0x3f,
  0xd7,
  0xe8,
  0xdc,
  0x2d,
  0x54,
  0xd1,
  0x40,
  0x5e,
  0xb2,
  0x89,
  0x16,
  0xb7,
  0xc8,
  0x6c,
  0x4e,
  0xeb,
  0x02,
  0x05,
  0xd3,
  0x83,
  0x98,
  0x69,
  0x2e,
  0x0a,
  0x50,
  0x51,
  0xf7,
  0xbc,
  0xcd,
  0x39,
  0xa3,
  0x15,
  0x2d,
  0xe9,
  0x9e,
  0xc4,
  0x1d,
  0x0d,
  0x36,
  0xdd,
  0xe2,
  0x7a,
  0x85,
  0x26,
  0xe3,
  0xcc,
  0x5a,
  0xc7,
  0xe4,
  0x8a,
  0xdb,
  0x28,
  0x51,
  0xb0,
  0xb2,
  0x7b,
  0x26,
  0xf8,
  0xb7,
  0x65,
  0x7e,
  0xd1,
  0x8b,
  0x39,
  0x52,
  0x7c,
  0x68,
  0x15,
  0x59,
  0xea,
  0x99,
  0xe9,
  0x3d,
  0x67,
  0xbf,
  0x5e,
  0x28,
  0xa7,
  0xa0,
  0xc2,
  0x75,
  0x14,
  0x76,
  0x97,
  0x62,
  0x52,
  0xe7,
  0xe7,
  0x27,
  0xde,
  0x8e,
  0x45,
  0x84,
  0xce,
  0x0f,
  0xad,
  0xc3,
  0x02,
  0x37,
  0x60,
  0xf5,
  0xb1,
  0x79,
  0x01,
  0x3c,
  0x9e,
  0xb8,
  0x50,
  0x87,
  0xb6,
  0x6f,
  0xb2,
  0x4d,
  0x99,
  0xee,
  0xea,
  0x2c,
  0xad,
  0x1b,
  0x62,
  0x5f,
  0x47,
  0xfb,
  0xf2,
  0xd8,
  0x0a,
  0x21,
  0x05,
  0x94,
  0x5d,
  0xc1,
  0xc3,
  0x3b,
  0x71,
  0xe7,
  0xa8,
  0xd4,
  0x61,
  0x80,
  0xf1,
  0x60,
  0xa2,
  0x99,
  0x0f,
  0xe0,
  0x0a,
  0xd7,
  0xbc,
  0x23,
  0x01,
  0xa6,
  0xf3,
  0xe7,
  0xa9,
  0xd1,
  0x66,
  0xd5,
  0x9e,
  0xd4,
  0xb9,
  0x61,
  0xe1,
  0xa4,
  0x47,
  0xae,
  0x12,
  0x0e,
  0x60,
  0x34,
  0x56,
  0x2d,
  0x28,
  0x6f,
  0x15,
  0xcd,
  0x13,
  0x8d,
  0xd5,
  0x9f,
  0xf7,
  0xf7,
  0x7f,
  0x4c,
  0x59,
  0xb8,
  0x5f,
  0x10,
  0x97,
  0xb6,
  0xd7,
  0x68,
  0x46,
  0x49,
  0xee,
  0xad,
  0x08,
  0x75,
  0x25,
  0xff,
  0x90,
  0x18,
  0xc6,
  0xaa,
  0x79,
  0x7e,
  0xd7,
  0x4d,
  0x83,
  0x1d,
  0x97,
  0x13,
  0x2e,
  0xef,
  0x4f,
  0x76,
  0x26,
  0xea,
  0x22,
  0x06,
  0xc5,
  0xd9,
  0xc0,
  0x62,
  0xce,
  0x68,
  0xde,
  0xc8,
  0xf3,
  0x2f,
  0xb7,
  0xae,
  0xdb,
  0xbc,
  0x37,
  0x8e,
  0x7c,
  0x3f,
};

/*----------------------------------------------------------------------------------------
 *           P R O T O T Y P E S     O F     L O C A L     F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                          E X P O R T E D    F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */
