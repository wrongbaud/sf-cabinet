/* Automatically generated, do not edit! */

static void
aw_fel_remotefunc_prepare_spi_batch_data_transfer(feldev_handle *dev,
                                                  uint32_t              buf,
                                                  uint32_t              spi_ctl_reg,
                                                  uint32_t              spi_ctl_xch_bitmask,
                                                  uint32_t              spi_fifo_reg,
                                                  uint32_t              spi_tx_reg,
                                                  uint32_t              spi_rx_reg,
                                                  uint32_t              spi_bc_reg,
                                                  uint32_t              spi_tc_reg,
                                                  uint32_t              spi_bcc_reg)
{
	static uint8_t arm_code[] = {
		0xf0, 0x4f, 0x2d, 0xe9, /*    0:    push     {r4, r5, r6, r7, r8, r9, sl, fp, lr} */
		0x24, 0xd0, 0x4d, 0xe2, /*    4:    sub      sp, sp, #36                        */
		0x48, 0x40, 0x9d, 0xe5, /*    8:    ldr      r4, [sp, #72]                      */
		0x4c, 0x90, 0x9d, 0xe5, /*    c:    ldr      r9, [sp, #76]                      */
		0x0c, 0x20, 0x8d, 0xe5, /*   10:    str      r2, [sp, #12]                      */
		0x1c, 0x20, 0x8d, 0xe2, /*   14:    add      r2, sp, #28                        */
		0x08, 0x10, 0x8d, 0xe5, /*   18:    str      r1, [sp, #8]                       */
		0x14, 0x20, 0x8d, 0xe5, /*   1c:    str      r2, [sp, #20]                      */
		0x00, 0x20, 0xd0, 0xe5, /*   20:    ldrb     r2, [r0]                           */
		0x01, 0x80, 0xd0, 0xe5, /*   24:    ldrb     r8, [r0, #1]                       */
		0x02, 0x84, 0x98, 0xe1, /*   28:    orrs     r8, r8, r2, lsl #8                 */
		0xbb, 0x00, 0x00, 0x0a, /*   2c:    beq      320 <spi_batch_data_transfer+0x320> */
		0x7c, 0x23, 0x9f, 0xe5, /*   30:    ldr      r2, [pc, #892]                     */
		0x02, 0x00, 0x58, 0xe1, /*   34:    cmp      r8, r2                             */
		0x58, 0x20, 0x9d, 0xe5, /*   38:    ldr      r2, [sp, #88]                      */
		0xc2, 0x00, 0x00, 0x0a, /*   3c:    beq      34c <spi_batch_data_transfer+0x34c> */
		0x00, 0x00, 0x52, 0xe3, /*   40:    cmp      r2, #0                             */
		0x50, 0x20, 0x9d, 0xe5, /*   44:    ldr      r2, [sp, #80]                      */
		0x08, 0xa0, 0xa0, 0xe1, /*   48:    mov      sl, r8                             */
		0x02, 0x00, 0x80, 0xe2, /*   4c:    add      r0, r0, #2                         */
		0x00, 0x80, 0x82, 0xe5, /*   50:    str      r8, [r2]                           */
		0x54, 0x20, 0x9d, 0xe5, /*   54:    ldr      r2, [sp, #84]                      */
		0x00, 0x80, 0x82, 0xe5, /*   58:    str      r8, [r2]                           */
		0x01, 0x00, 0x00, 0x0a, /*   5c:    beq      68 <spi_batch_data_transfer+0x68>  */
		0x58, 0x20, 0x9d, 0xe5, /*   60:    ldr      r2, [sp, #88]                      */
		0x00, 0xa0, 0x82, 0xe5, /*   64:    str      sl, [r2]                           */
		0x00, 0x10, 0x60, 0xe2, /*   68:    rsb      r1, r0, #0                         */
		0x03, 0x10, 0x01, 0xe2, /*   6c:    and      r1, r1, #3                         */
		0x3c, 0x20, 0x81, 0xe2, /*   70:    add      r2, r1, #60                        */
		0x0a, 0x00, 0x52, 0xe1, /*   74:    cmp      r2, sl                             */
		0x0a, 0x20, 0xa0, 0x21, /*   78:    movcs    r2, sl                             */
		0x0a, 0x00, 0x51, 0xe1, /*   7c:    cmp      r1, sl                             */
		0x01, 0x60, 0x42, 0xe2, /*   80:    sub      r6, r2, #1                         */
		0x0a, 0x10, 0xa0, 0x21, /*   84:    movcs    r1, sl                             */
		0x1f, 0x00, 0x56, 0xe3, /*   88:    cmp      r6, #31                            */
		0xbd, 0x00, 0x00, 0x9a, /*   8c:    bls      388 <spi_batch_data_transfer+0x388> */
		0x00, 0xe0, 0xa0, 0xe1, /*   90:    mov      lr, r0                             */
		0x22, 0xf0, 0xd0, 0xf5, /*   94:    pld      [r0, #34]                          */
		0x20, 0x50, 0xde, 0xe4, /*   98:    ldrb     r5, [lr], #32                      */
		0x21, 0xc0, 0x42, 0xe2, /*   9c:    sub      ip, r2, #33                        */
		0x00, 0x50, 0xc4, 0xe5, /*   a0:    strb     r5, [r4]                           */
		0x0e, 0x20, 0xa0, 0xe1, /*   a4:    mov      r2, lr                             */
		0x1f, 0x50, 0x5e, 0xe5, /*   a8:    ldrb     r5, [lr, #-31]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   ac:    strb     r5, [r4]                           */
		0x1e, 0x50, 0x5e, 0xe5, /*   b0:    ldrb     r5, [lr, #-30]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   b4:    strb     r5, [r4]                           */
		0x1d, 0x50, 0x5e, 0xe5, /*   b8:    ldrb     r5, [lr, #-29]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   bc:    strb     r5, [r4]                           */
		0x1c, 0x50, 0x5e, 0xe5, /*   c0:    ldrb     r5, [lr, #-28]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   c4:    strb     r5, [r4]                           */
		0x1b, 0x50, 0x5e, 0xe5, /*   c8:    ldrb     r5, [lr, #-27]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   cc:    strb     r5, [r4]                           */
		0x1a, 0x50, 0x5e, 0xe5, /*   d0:    ldrb     r5, [lr, #-26]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   d4:    strb     r5, [r4]                           */
		0x19, 0x50, 0x5e, 0xe5, /*   d8:    ldrb     r5, [lr, #-25]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   dc:    strb     r5, [r4]                           */
		0x18, 0x50, 0x5e, 0xe5, /*   e0:    ldrb     r5, [lr, #-24]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   e4:    strb     r5, [r4]                           */
		0x17, 0x50, 0x5e, 0xe5, /*   e8:    ldrb     r5, [lr, #-23]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   ec:    strb     r5, [r4]                           */
		0x16, 0x50, 0x5e, 0xe5, /*   f0:    ldrb     r5, [lr, #-22]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   f4:    strb     r5, [r4]                           */
		0x15, 0x50, 0x5e, 0xe5, /*   f8:    ldrb     r5, [lr, #-21]                     */
		0x00, 0x50, 0xc4, 0xe5, /*   fc:    strb     r5, [r4]                           */
		0x14, 0x50, 0x5e, 0xe5, /*  100:    ldrb     r5, [lr, #-20]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  104:    strb     r5, [r4]                           */
		0x13, 0x50, 0x5e, 0xe5, /*  108:    ldrb     r5, [lr, #-19]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  10c:    strb     r5, [r4]                           */
		0x12, 0x50, 0x5e, 0xe5, /*  110:    ldrb     r5, [lr, #-18]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  114:    strb     r5, [r4]                           */
		0x11, 0x50, 0x5e, 0xe5, /*  118:    ldrb     r5, [lr, #-17]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  11c:    strb     r5, [r4]                           */
		0x10, 0x50, 0x5e, 0xe5, /*  120:    ldrb     r5, [lr, #-16]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  124:    strb     r5, [r4]                           */
		0x0f, 0x50, 0x5e, 0xe5, /*  128:    ldrb     r5, [lr, #-15]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  12c:    strb     r5, [r4]                           */
		0x0e, 0x50, 0x5e, 0xe5, /*  130:    ldrb     r5, [lr, #-14]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  134:    strb     r5, [r4]                           */
		0x0d, 0x50, 0x5e, 0xe5, /*  138:    ldrb     r5, [lr, #-13]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  13c:    strb     r5, [r4]                           */
		0x0c, 0x50, 0x5e, 0xe5, /*  140:    ldrb     r5, [lr, #-12]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  144:    strb     r5, [r4]                           */
		0x0b, 0x50, 0x5e, 0xe5, /*  148:    ldrb     r5, [lr, #-11]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  14c:    strb     r5, [r4]                           */
		0x0a, 0x50, 0x5e, 0xe5, /*  150:    ldrb     r5, [lr, #-10]                     */
		0x00, 0x50, 0xc4, 0xe5, /*  154:    strb     r5, [r4]                           */
		0x09, 0x50, 0x5e, 0xe5, /*  158:    ldrb     r5, [lr, #-9]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  15c:    strb     r5, [r4]                           */
		0x08, 0x50, 0x5e, 0xe5, /*  160:    ldrb     r5, [lr, #-8]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  164:    strb     r5, [r4]                           */
		0x07, 0x50, 0x5e, 0xe5, /*  168:    ldrb     r5, [lr, #-7]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  16c:    strb     r5, [r4]                           */
		0x06, 0x50, 0x5e, 0xe5, /*  170:    ldrb     r5, [lr, #-6]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  174:    strb     r5, [r4]                           */
		0x05, 0x50, 0x5e, 0xe5, /*  178:    ldrb     r5, [lr, #-5]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  17c:    strb     r5, [r4]                           */
		0x04, 0x50, 0x5e, 0xe5, /*  180:    ldrb     r5, [lr, #-4]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  184:    strb     r5, [r4]                           */
		0x03, 0x50, 0x5e, 0xe5, /*  188:    ldrb     r5, [lr, #-3]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  18c:    strb     r5, [r4]                           */
		0x02, 0x50, 0x5e, 0xe5, /*  190:    ldrb     r5, [lr, #-2]                      */
		0x00, 0x50, 0xc4, 0xe5, /*  194:    strb     r5, [r4]                           */
		0x01, 0xe0, 0x5e, 0xe5, /*  198:    ldrb     lr, [lr, #-1]                      */
		0x00, 0xe0, 0xc4, 0xe5, /*  19c:    strb     lr, [r4]                           */
		0x0c, 0xe0, 0x82, 0xe0, /*  1a0:    add      lr, r2, ip                         */
		0x01, 0x20, 0x42, 0xe2, /*  1a4:    sub      r2, r2, #1                         */
		0x01, 0xc0, 0xf2, 0xe5, /*  1a8:    ldrb     ip, [r2, #1]!                      */
		0x0e, 0x00, 0x52, 0xe1, /*  1ac:    cmp      r2, lr                             */
		0x00, 0xc0, 0xc4, 0xe5, /*  1b0:    strb     ip, [r4]                           */
		0xfb, 0xff, 0xff, 0x1a, /*  1b4:    bne      1a8 <spi_batch_data_transfer+0x1a8> */
		0x01, 0x50, 0x86, 0xe2, /*  1b8:    add      r5, r6, #1                         */
		0x01, 0xc0, 0x4a, 0xe2, /*  1bc:    sub      ip, sl, #1                         */
		0x05, 0x50, 0x80, 0xe0, /*  1c0:    add      r5, r0, r5                         */
		0x06, 0xc0, 0x4c, 0xe0, /*  1c4:    sub      ip, ip, r6                         */
		0x00, 0xb0, 0x0f, 0xe1, /*  1c8:    mrs      fp, CPSR                           */
		0xc0, 0x20, 0x8b, 0xe3, /*  1cc:    orr      r2, fp, #192                       */
		0x02, 0xf0, 0x21, 0xe1, /*  1d0:    msr      CPSR_c, r2                         */
		0x08, 0x70, 0x9d, 0xe5, /*  1d4:    ldr      r7, [sp, #8]                       */
		0x01, 0x20, 0x80, 0xe0, /*  1d8:    add      r2, r0, r1                         */
		0x04, 0x20, 0x8d, 0xe5, /*  1dc:    str      r2, [sp, #4]                       */
		0x00, 0xe0, 0xa0, 0xe1, /*  1e0:    mov      lr, r0                             */
		0x0c, 0x20, 0x9d, 0xe5, /*  1e4:    ldr      r2, [sp, #12]                      */
		0x00, 0x60, 0x97, 0xe5, /*  1e8:    ldr      r6, [r7]                           */
		0x06, 0x60, 0x82, 0xe1, /*  1ec:    orr      r6, r2, r6                         */
		0x04, 0x20, 0x9d, 0xe5, /*  1f0:    ldr      r2, [sp, #4]                       */
		0x00, 0x60, 0x87, 0xe5, /*  1f4:    str      r6, [r7]                           */
		0x0e, 0x00, 0x52, 0xe1, /*  1f8:    cmp      r2, lr                             */
		0x06, 0x00, 0x00, 0x0a, /*  1fc:    beq      21c <spi_batch_data_transfer+0x21c> */
		0x00, 0x60, 0x93, 0xe5, /*  200:    ldr      r6, [r3]                           */
		0x7f, 0x00, 0x16, 0xe3, /*  204:    tst      r6, #127                           */
		0xfc, 0xff, 0xff, 0x0a, /*  208:    beq      200 <spi_batch_data_transfer+0x200> */
		0x00, 0x60, 0xd9, 0xe5, /*  20c:    ldrb     r6, [r9]                           */
		0x01, 0x60, 0xce, 0xe4, /*  210:    strb     r6, [lr], #1                       */
		0x0e, 0x00, 0x52, 0xe1, /*  214:    cmp      r2, lr                             */
		0xf8, 0xff, 0xff, 0x1a, /*  218:    bne      200 <spi_batch_data_transfer+0x200> */
		0x01, 0x10, 0x4a, 0xe0, /*  21c:    sub      r1, sl, r1                         */
		0x03, 0x00, 0x51, 0xe3, /*  220:    cmp      r1, #3                             */
		0x15, 0x00, 0x00, 0x9a, /*  224:    bls      280 <spi_batch_data_transfer+0x280> */
		0x02, 0xe0, 0xa0, 0xe1, /*  228:    mov      lr, r2                             */
		0x00, 0x20, 0x93, 0xe5, /*  22c:    ldr      r2, [r3]                           */
		0x7f, 0x60, 0x02, 0xe2, /*  230:    and      r6, r2, #127                       */
		0x03, 0x00, 0x56, 0xe3, /*  234:    cmp      r6, #3                             */
		0x22, 0x28, 0xa0, 0xe1, /*  238:    lsr      r2, r2, #16                        */
		0x00, 0x60, 0x99, 0xc5, /*  23c:    ldrgt    r6, [r9]                           */
		0x04, 0x10, 0x41, 0xc2, /*  240:    subgt    r1, r1, #4                         */
		0x7f, 0x20, 0x02, 0xe2, /*  244:    and      r2, r2, #127                       */
		0x00, 0x60, 0x8e, 0xc5, /*  248:    strgt    r6, [lr]                           */
		0x04, 0xe0, 0x8e, 0xc2, /*  24c:    addgt    lr, lr, #4                         */
		0x3b, 0x00, 0x52, 0xe3, /*  250:    cmp      r2, #59                            */
		0x00, 0x20, 0xa0, 0xc3, /*  254:    movgt    r2, #0                             */
		0x01, 0x20, 0xa0, 0xd3, /*  258:    movle    r2, #1                             */
		0x03, 0x00, 0x5c, 0xe3, /*  25c:    cmp      ip, #3                             */
		0x00, 0x20, 0xa0, 0x93, /*  260:    movls    r2, #0                             */
		0x00, 0x00, 0x52, 0xe3, /*  264:    cmp      r2, #0                             */
		0x00, 0x20, 0x95, 0x15, /*  268:    ldrne    r2, [r5]                           */
		0x04, 0xc0, 0x4c, 0x12, /*  26c:    subne    ip, ip, #4                         */
		0x04, 0x50, 0x85, 0x12, /*  270:    addne    r5, r5, #4                         */
		0x00, 0x20, 0x84, 0x15, /*  274:    strne    r2, [r4]                           */
		0x03, 0x00, 0x51, 0xe3, /*  278:    cmp      r1, #3                             */
		0xea, 0xff, 0xff, 0x8a, /*  27c:    bhi      22c <spi_batch_data_transfer+0x22c> */
		0x00, 0x00, 0x51, 0xe3, /*  280:    cmp      r1, #0                             */
		0x17, 0x00, 0x00, 0x0a, /*  284:    beq      2e8 <spi_batch_data_transfer+0x2e8> */
		0x00, 0x20, 0x93, 0xe5, /*  288:    ldr      r2, [r3]                           */
		0x01, 0x60, 0x8e, 0xe2, /*  28c:    add      r6, lr, #1                         */
		0x7f, 0x00, 0x12, 0xe3, /*  290:    tst      r2, #127                           */
		0x22, 0x28, 0xa0, 0xe1, /*  294:    lsr      r2, r2, #16                        */
		0x7f, 0x20, 0x02, 0xe2, /*  298:    and      r2, r2, #127                       */
		0x21, 0x00, 0x00, 0x0a, /*  29c:    beq      328 <spi_batch_data_transfer+0x328> */
		0x3b, 0x00, 0x52, 0xe3, /*  2a0:    cmp      r2, #59                            */
		0x00, 0x70, 0xd9, 0xe5, /*  2a4:    ldrb     r7, [r9]                           */
		0x00, 0x20, 0xa0, 0xc3, /*  2a8:    movgt    r2, #0                             */
		0x01, 0x20, 0xa0, 0xd3, /*  2ac:    movle    r2, #1                             */
		0x00, 0x00, 0x5c, 0xe3, /*  2b0:    cmp      ip, #0                             */
		0x01, 0x10, 0x41, 0xe2, /*  2b4:    sub      r1, r1, #1                         */
		0x00, 0x20, 0xa0, 0x03, /*  2b8:    moveq    r2, #0                             */
		0x00, 0x70, 0xce, 0xe5, /*  2bc:    strb     r7, [lr]                           */
		0x00, 0x00, 0x52, 0xe3, /*  2c0:    cmp      r2, #0                             */
		0x06, 0xe0, 0xa0, 0xe1, /*  2c4:    mov      lr, r6                             */
		0xec, 0xff, 0xff, 0x0a, /*  2c8:    beq      280 <spi_batch_data_transfer+0x280> */
		0x00, 0x20, 0xd5, 0xe5, /*  2cc:    ldrb     r2, [r5]                           */
		0x00, 0x00, 0x51, 0xe3, /*  2d0:    cmp      r1, #0                             */
		0x01, 0xc0, 0x4c, 0xe2, /*  2d4:    sub      ip, ip, #1                         */
		0x06, 0xe0, 0xa0, 0xe1, /*  2d8:    mov      lr, r6                             */
		0x01, 0x50, 0x85, 0xe2, /*  2dc:    add      r5, r5, #1                         */
		0x00, 0x20, 0xc4, 0xe5, /*  2e0:    strb     r2, [r4]                           */
		0xe7, 0xff, 0xff, 0x1a, /*  2e4:    bne      288 <spi_batch_data_transfer+0x288> */
		0x0b, 0xf0, 0x21, 0xe1, /*  2e8:    msr      CPSR_c, fp                         */
		0xc0, 0x20, 0x9f, 0xe5, /*  2ec:    ldr      r2, [pc, #192]                     */
		0x02, 0x00, 0x58, 0xe1, /*  2f0:    cmp      r8, r2                             */
		0x0a, 0x00, 0x80, 0x10, /*  2f4:    addne    r0, r0, sl                         */
		0x48, 0xff, 0xff, 0x1a, /*  2f8:    bne      20 <spi_batch_data_transfer+0x20>  */
		0x1d, 0x20, 0xdd, 0xe5, /*  2fc:    ldrb     r2, [sp, #29]                      */
		0x01, 0x00, 0x12, 0xe3, /*  300:    tst      r2, #1                             */
		0x1d, 0x00, 0x00, 0x1a, /*  304:    bne      380 <spi_batch_data_transfer+0x380> */
		0x10, 0x20, 0x9d, 0xe5, /*  308:    ldr      r2, [sp, #16]                      */
		0x02, 0x00, 0x82, 0xe2, /*  30c:    add      r0, r2, #2                         */
		0x01, 0x80, 0xd0, 0xe5, /*  310:    ldrb     r8, [r0, #1]                       */
		0x00, 0x20, 0xd0, 0xe5, /*  314:    ldrb     r2, [r0]                           */
		0x02, 0x84, 0x98, 0xe1, /*  318:    orrs     r8, r8, r2, lsl #8                 */
		0x43, 0xff, 0xff, 0x1a, /*  31c:    bne      30 <spi_batch_data_transfer+0x30>  */
		0x24, 0xd0, 0x8d, 0xe2, /*  320:    add      sp, sp, #36                        */
		0xf0, 0x8f, 0xbd, 0xe8, /*  324:    pop      {r4, r5, r6, r7, r8, r9, sl, fp, pc} */
		0x3b, 0x00, 0x52, 0xe3, /*  328:    cmp      r2, #59                            */
		0x0e, 0x60, 0xa0, 0xe1, /*  32c:    mov      r6, lr                             */
		0x00, 0x20, 0xa0, 0xc3, /*  330:    movgt    r2, #0                             */
		0x01, 0x20, 0xa0, 0xd3, /*  334:    movle    r2, #1                             */
		0x00, 0x00, 0x5c, 0xe3, /*  338:    cmp      ip, #0                             */
		0x00, 0x20, 0xa0, 0x03, /*  33c:    moveq    r2, #0                             */
		0x00, 0x00, 0x52, 0xe3, /*  340:    cmp      r2, #0                             */
		0xe0, 0xff, 0xff, 0x1a, /*  344:    bne      2cc <spi_batch_data_transfer+0x2cc> */
		0xce, 0xff, 0xff, 0xea, /*  348:    b        288 <spi_batch_data_transfer+0x288> */
		0x00, 0x00, 0x52, 0xe3, /*  34c:    cmp      r2, #0                             */
		0x50, 0x20, 0x9d, 0xe5, /*  350:    ldr      r2, [sp, #80]                      */
		0x02, 0x10, 0xa0, 0xe3, /*  354:    mov      r1, #2                             */
		0x00, 0x10, 0x82, 0xe5, /*  358:    str      r1, [r2]                           */
		0x05, 0x20, 0xa0, 0xe3, /*  35c:    mov      r2, #5                             */
		0x1c, 0x20, 0xcd, 0xe5, /*  360:    strb     r2, [sp, #28]                      */
		0x54, 0x20, 0x9d, 0xe5, /*  364:    ldr      r2, [sp, #84]                      */
		0x00, 0x10, 0x82, 0xe5, /*  368:    str      r1, [r2]                           */
		0x08, 0x00, 0x00, 0x0a, /*  36c:    beq      394 <spi_batch_data_transfer+0x394> */
		0x10, 0x00, 0x8d, 0xe5, /*  370:    str      r0, [sp, #16]                      */
		0x02, 0xa0, 0xa0, 0xe3, /*  374:    mov      sl, #2                             */
		0x14, 0x00, 0x9d, 0xe5, /*  378:    ldr      r0, [sp, #20]                      */
		0x37, 0xff, 0xff, 0xea, /*  37c:    b        60 <spi_batch_data_transfer+0x60>  */
		0x10, 0x00, 0x9d, 0xe5, /*  380:    ldr      r0, [sp, #16]                      */
		0x25, 0xff, 0xff, 0xea, /*  384:    b        20 <spi_batch_data_transfer+0x20>  */
		0x06, 0xc0, 0xa0, 0xe1, /*  388:    mov      ip, r6                             */
		0x00, 0x20, 0xa0, 0xe1, /*  38c:    mov      r2, r0                             */
		0x82, 0xff, 0xff, 0xea, /*  390:    b        1a0 <spi_batch_data_transfer+0x1a0> */
		0x14, 0x20, 0x9d, 0xe5, /*  394:    ldr      r2, [sp, #20]                      */
		0x01, 0x60, 0xa0, 0xe3, /*  398:    mov      r6, #1                             */
		0x10, 0x00, 0x8d, 0xe5, /*  39c:    str      r0, [sp, #16]                      */
		0x06, 0xc0, 0xa0, 0xe1, /*  3a0:    mov      ip, r6                             */
		0x58, 0x10, 0x9d, 0xe5, /*  3a4:    ldr      r1, [sp, #88]                      */
		0x02, 0xa0, 0xa0, 0xe3, /*  3a8:    mov      sl, #2                             */
		0x02, 0x00, 0xa0, 0xe1, /*  3ac:    mov      r0, r2                             */
		0x7a, 0xff, 0xff, 0xea, /*  3b0:    b        1a0 <spi_batch_data_transfer+0x1a0> */
		0xff, 0xff, 0x00, 0x00, /*  3b4:    .word    0x0000ffff                         */
	};
	uint32_t args[] = {
		buf,
		spi_ctl_reg,
		spi_ctl_xch_bitmask,
		spi_fifo_reg,
		spi_tx_reg,
		spi_rx_reg,
		spi_bc_reg,
		spi_tc_reg,
		spi_bcc_reg
	};
	aw_fel_remotefunc_prepare(dev, 72, arm_code, sizeof(arm_code), 9, args);
}
