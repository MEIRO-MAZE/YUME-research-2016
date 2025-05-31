
;CodeVisionAVR C Compiler V2.05.0 Professional
;(C) Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com

;Chip type                : ATmega8
;Program type             : Application
;Clock frequency          : 16.000000 MHz
;Memory model             : Small
;Optimize for             : Size
;(s)printf features       : int, width
;(s)scanf features        : int, width
;External RAM size        : 0
;Data Stack size          : 256 byte(s)
;Heap size                : 0 byte(s)
;Promote 'char' to 'int'  : Yes
;'char' is unsigned       : Yes
;8 bit enums              : Yes
;global 'const' stored in FLASH: No
;Enhanced core instructions    : On
;Smart register allocation     : On
;Automatic register allocation : On

	#pragma AVRPART ADMIN PART_NAME ATmega8
	#pragma AVRPART MEMORY PROG_FLASH 8192
	#pragma AVRPART MEMORY EEPROM 512
	#pragma AVRPART MEMORY INT_SRAM SIZE 1119
	#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x60

	.LISTMAC
	.EQU UDRE=0x5
	.EQU RXC=0x7
	.EQU USR=0xB
	.EQU UDR=0xC
	.EQU SPSR=0xE
	.EQU SPDR=0xF
	.EQU EERE=0x0
	.EQU EEWE=0x1
	.EQU EEMWE=0x2
	.EQU EECR=0x1C
	.EQU EEDR=0x1D
	.EQU EEARL=0x1E
	.EQU EEARH=0x1F
	.EQU WDTCR=0x21
	.EQU MCUCR=0x35
	.EQU GICR=0x3B
	.EQU SPL=0x3D
	.EQU SPH=0x3E
	.EQU SREG=0x3F

	.DEF R0X0=R0
	.DEF R0X1=R1
	.DEF R0X2=R2
	.DEF R0X3=R3
	.DEF R0X4=R4
	.DEF R0X5=R5
	.DEF R0X6=R6
	.DEF R0X7=R7
	.DEF R0X8=R8
	.DEF R0X9=R9
	.DEF R0XA=R10
	.DEF R0XB=R11
	.DEF R0XC=R12
	.DEF R0XD=R13
	.DEF R0XE=R14
	.DEF R0XF=R15
	.DEF R0X10=R16
	.DEF R0X11=R17
	.DEF R0X12=R18
	.DEF R0X13=R19
	.DEF R0X14=R20
	.DEF R0X15=R21
	.DEF R0X16=R22
	.DEF R0X17=R23
	.DEF R0X18=R24
	.DEF R0X19=R25
	.DEF R0X1A=R26
	.DEF R0X1B=R27
	.DEF R0X1C=R28
	.DEF R0X1D=R29
	.DEF R0X1E=R30
	.DEF R0X1F=R31

	.EQU __SRAM_START=0x0060
	.EQU __SRAM_END=0x045F
	.EQU __DSTACK_SIZE=0x0100
	.EQU __HEAP_SIZE=0x0000
	.EQU __CLEAR_SRAM_SIZE=__SRAM_END-__SRAM_START+1

	.MACRO __CPD1N
	CPI  R30,LOW(@0)
	LDI  R26,HIGH(@0)
	CPC  R31,R26
	LDI  R26,BYTE3(@0)
	CPC  R22,R26
	LDI  R26,BYTE4(@0)
	CPC  R23,R26
	.ENDM

	.MACRO __CPD2N
	CPI  R26,LOW(@0)
	LDI  R30,HIGH(@0)
	CPC  R27,R30
	LDI  R30,BYTE3(@0)
	CPC  R24,R30
	LDI  R30,BYTE4(@0)
	CPC  R25,R30
	.ENDM

	.MACRO __CPWRR
	CP   R@0,R@2
	CPC  R@1,R@3
	.ENDM

	.MACRO __CPWRN
	CPI  R@0,LOW(@2)
	LDI  R30,HIGH(@2)
	CPC  R@1,R30
	.ENDM

	.MACRO __ADDB1MN
	SUBI R30,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDB2MN
	SUBI R26,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDW1MN
	SUBI R30,LOW(-@0-(@1))
	SBCI R31,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW2MN
	SUBI R26,LOW(-@0-(@1))
	SBCI R27,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	SBCI R22,BYTE3(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1N
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	SBCI R22,BYTE3(-@0)
	SBCI R23,BYTE4(-@0)
	.ENDM

	.MACRO __ADDD2N
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	SBCI R24,BYTE3(-@0)
	SBCI R25,BYTE4(-@0)
	.ENDM

	.MACRO __SUBD1N
	SUBI R30,LOW(@0)
	SBCI R31,HIGH(@0)
	SBCI R22,BYTE3(@0)
	SBCI R23,BYTE4(@0)
	.ENDM

	.MACRO __SUBD2N
	SUBI R26,LOW(@0)
	SBCI R27,HIGH(@0)
	SBCI R24,BYTE3(@0)
	SBCI R25,BYTE4(@0)
	.ENDM

	.MACRO __ANDBMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ANDWMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ANDI R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ANDD1N
	ANDI R30,LOW(@0)
	ANDI R31,HIGH(@0)
	ANDI R22,BYTE3(@0)
	ANDI R23,BYTE4(@0)
	.ENDM

	.MACRO __ANDD2N
	ANDI R26,LOW(@0)
	ANDI R27,HIGH(@0)
	ANDI R24,BYTE3(@0)
	ANDI R25,BYTE4(@0)
	.ENDM

	.MACRO __ORBMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ORWMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ORI  R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ORD1N
	ORI  R30,LOW(@0)
	ORI  R31,HIGH(@0)
	ORI  R22,BYTE3(@0)
	ORI  R23,BYTE4(@0)
	.ENDM

	.MACRO __ORD2N
	ORI  R26,LOW(@0)
	ORI  R27,HIGH(@0)
	ORI  R24,BYTE3(@0)
	ORI  R25,BYTE4(@0)
	.ENDM

	.MACRO __DELAY_USB
	LDI  R24,LOW(@0)
__DELAY_USB_LOOP:
	DEC  R24
	BRNE __DELAY_USB_LOOP
	.ENDM

	.MACRO __DELAY_USW
	LDI  R24,LOW(@0)
	LDI  R25,HIGH(@0)
__DELAY_USW_LOOP:
	SBIW R24,1
	BRNE __DELAY_USW_LOOP
	.ENDM

	.MACRO __GETD1S
	LDD  R30,Y+@0
	LDD  R31,Y+@0+1
	LDD  R22,Y+@0+2
	LDD  R23,Y+@0+3
	.ENDM

	.MACRO __GETD2S
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	LDD  R24,Y+@0+2
	LDD  R25,Y+@0+3
	.ENDM

	.MACRO __PUTD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R31
	STD  Y+@0+2,R22
	STD  Y+@0+3,R23
	.ENDM

	.MACRO __PUTD2S
	STD  Y+@0,R26
	STD  Y+@0+1,R27
	STD  Y+@0+2,R24
	STD  Y+@0+3,R25
	.ENDM

	.MACRO __PUTDZ2
	STD  Z+@0,R26
	STD  Z+@0+1,R27
	STD  Z+@0+2,R24
	STD  Z+@0+3,R25
	.ENDM

	.MACRO __CLRD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R30
	STD  Y+@0+2,R30
	STD  Y+@0+3,R30
	.ENDM

	.MACRO __POINTB1MN
	LDI  R30,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW1MN
	LDI  R30,LOW(@0+(@1))
	LDI  R31,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD1M
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __POINTW1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	LDI  R22,BYTE3(2*@0+(@1))
	LDI  R23,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTB2MN
	LDI  R26,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW2MN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTBRM
	LDI  R@0,LOW(@1)
	.ENDM

	.MACRO __POINTWRM
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __POINTBRMN
	LDI  R@0,LOW(@1+(@2))
	.ENDM

	.MACRO __POINTWRMN
	LDI  R@0,LOW(@2+(@3))
	LDI  R@1,HIGH(@2+(@3))
	.ENDM

	.MACRO __POINTWRFN
	LDI  R@0,LOW(@2*2+(@3))
	LDI  R@1,HIGH(@2*2+(@3))
	.ENDM

	.MACRO __GETD1N
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __GETD2N
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __GETB1MN
	LDS  R30,@0+(@1)
	.ENDM

	.MACRO __GETB1HMN
	LDS  R31,@0+(@1)
	.ENDM

	.MACRO __GETW1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	.ENDM

	.MACRO __GETD1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	LDS  R22,@0+(@1)+2
	LDS  R23,@0+(@1)+3
	.ENDM

	.MACRO __GETBRMN
	LDS  R@0,@1+(@2)
	.ENDM

	.MACRO __GETWRMN
	LDS  R@0,@2+(@3)
	LDS  R@1,@2+(@3)+1
	.ENDM

	.MACRO __GETWRZ
	LDD  R@0,Z+@2
	LDD  R@1,Z+@2+1
	.ENDM

	.MACRO __GETD2Z
	LDD  R26,Z+@0
	LDD  R27,Z+@0+1
	LDD  R24,Z+@0+2
	LDD  R25,Z+@0+3
	.ENDM

	.MACRO __GETB2MN
	LDS  R26,@0+(@1)
	.ENDM

	.MACRO __GETW2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	.ENDM

	.MACRO __GETD2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	LDS  R24,@0+(@1)+2
	LDS  R25,@0+(@1)+3
	.ENDM

	.MACRO __PUTB1MN
	STS  @0+(@1),R30
	.ENDM

	.MACRO __PUTW1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	.ENDM

	.MACRO __PUTD1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	STS  @0+(@1)+2,R22
	STS  @0+(@1)+3,R23
	.ENDM

	.MACRO __PUTB1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRB
	.ENDM

	.MACRO __PUTW1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRW
	.ENDM

	.MACRO __PUTD1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRD
	.ENDM

	.MACRO __PUTBR0MN
	STS  @0+(@1),R0
	.ENDM

	.MACRO __PUTBMRN
	STS  @0+(@1),R@2
	.ENDM

	.MACRO __PUTWMRN
	STS  @0+(@1),R@2
	STS  @0+(@1)+1,R@3
	.ENDM

	.MACRO __PUTBZR
	STD  Z+@1,R@0
	.ENDM

	.MACRO __PUTWZR
	STD  Z+@2,R@0
	STD  Z+@2+1,R@1
	.ENDM

	.MACRO __GETW1R
	MOV  R30,R@0
	MOV  R31,R@1
	.ENDM

	.MACRO __GETW2R
	MOV  R26,R@0
	MOV  R27,R@1
	.ENDM

	.MACRO __GETWRN
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __PUTW1R
	MOV  R@0,R30
	MOV  R@1,R31
	.ENDM

	.MACRO __PUTW2R
	MOV  R@0,R26
	MOV  R@1,R27
	.ENDM

	.MACRO __ADDWRN
	SUBI R@0,LOW(-@2)
	SBCI R@1,HIGH(-@2)
	.ENDM

	.MACRO __ADDWRR
	ADD  R@0,R@2
	ADC  R@1,R@3
	.ENDM

	.MACRO __SUBWRN
	SUBI R@0,LOW(@2)
	SBCI R@1,HIGH(@2)
	.ENDM

	.MACRO __SUBWRR
	SUB  R@0,R@2
	SBC  R@1,R@3
	.ENDM

	.MACRO __ANDWRN
	ANDI R@0,LOW(@2)
	ANDI R@1,HIGH(@2)
	.ENDM

	.MACRO __ANDWRR
	AND  R@0,R@2
	AND  R@1,R@3
	.ENDM

	.MACRO __ORWRN
	ORI  R@0,LOW(@2)
	ORI  R@1,HIGH(@2)
	.ENDM

	.MACRO __ORWRR
	OR   R@0,R@2
	OR   R@1,R@3
	.ENDM

	.MACRO __EORWRR
	EOR  R@0,R@2
	EOR  R@1,R@3
	.ENDM

	.MACRO __GETWRS
	LDD  R@0,Y+@2
	LDD  R@1,Y+@2+1
	.ENDM

	.MACRO __PUTBSR
	STD  Y+@1,R@0
	.ENDM

	.MACRO __PUTWSR
	STD  Y+@2,R@0
	STD  Y+@2+1,R@1
	.ENDM

	.MACRO __MOVEWRR
	MOV  R@0,R@2
	MOV  R@1,R@3
	.ENDM

	.MACRO __INWR
	IN   R@0,@2
	IN   R@1,@2+1
	.ENDM

	.MACRO __OUTWR
	OUT  @2+1,R@1
	OUT  @2,R@0
	.ENDM

	.MACRO __CALL1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	ICALL
	.ENDM

	.MACRO __CALL1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	RCALL __GETW1PF
	ICALL
	.ENDM

	.MACRO __CALL2EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMRDW
	ICALL
	.ENDM

	.MACRO __GETW1STACK
	IN   R26,SPL
	IN   R27,SPH
	ADIW R26,@0+1
	LD   R30,X+
	LD   R31,X
	.ENDM

	.MACRO __GETD1STACK
	IN   R26,SPL
	IN   R27,SPH
	ADIW R26,@0+1
	LD   R30,X+
	LD   R31,X+
	LD   R22,X
	.ENDM

	.MACRO __NBST
	BST  R@0,@1
	IN   R30,SREG
	LDI  R31,0x40
	EOR  R30,R31
	OUT  SREG,R30
	.ENDM


	.MACRO __PUTB1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RNS
	MOVW R26,R@0
	ADIW R26,@1
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	RCALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	RCALL __PUTDP1
	.ENDM


	.MACRO __GETB1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R30,Z
	.ENDM

	.MACRO __GETB1HSX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	.ENDM

	.MACRO __GETW1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z+
	LD   R23,Z
	MOVW R30,R0
	.ENDM

	.MACRO __GETB2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R26,X
	.ENDM

	.MACRO __GETW2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	.ENDM

	.MACRO __GETD2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R1,X+
	LD   R24,X+
	LD   R25,X
	MOVW R26,R0
	.ENDM

	.MACRO __GETBRSX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	LD   R@0,Z
	.ENDM

	.MACRO __GETWRSX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	LD   R@0,Z+
	LD   R@1,Z
	.ENDM

	.MACRO __GETBRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	LD   R@0,X
	.ENDM

	.MACRO __GETWRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	LD   R@0,X+
	LD   R@1,X
	.ENDM

	.MACRO __LSLW8SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	CLR  R30
	.ENDM

	.MACRO __PUTB1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __CLRW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __CLRD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R30
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __PUTB2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z,R26
	.ENDM

	.MACRO __PUTW2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z,R27
	.ENDM

	.MACRO __PUTD2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z+,R27
	ST   Z+,R24
	ST   Z,R25
	.ENDM

	.MACRO __PUTBSRX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	ST   Z,R@0
	.ENDM

	.MACRO __PUTWSRX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	ST   Z+,R@0
	ST   Z,R@1
	.ENDM

	.MACRO __PUTB1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __MULBRR
	MULS R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRRU
	MUL  R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRR0
	MULS R@0,R@1
	.ENDM

	.MACRO __MULBRRU0
	MUL  R@0,R@1
	.ENDM

	.MACRO __MULBNWRU
	LDI  R26,@2
	MUL  R26,R@0
	MOVW R30,R0
	MUL  R26,R@1
	ADD  R31,R0
	.ENDM

;NAME DEFINITIONS FOR GLOBAL VARIABLES ALLOCATED TO REGISTERS
	.DEF _COMMAND_FLAG_A=R4
	.DEF _COMMAND_FLAG_B=R6
	.DEF _flag=R9
	.DEF _schedule=R8
	.DEF _eksekusi=R10
	.DEF _baud_mode=R12

	.CSEG
	.ORG 0x00

;START OF CODE MARKER
__START_OF_CODE:

;INTERRUPT VECTORS
	RJMP __RESET
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP _timer1_compa_isr
	RJMP _timer1_compb_isr
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00

_tbl10_G101:
	.DB  0x10,0x27,0xE8,0x3,0x64,0x0,0xA,0x0
	.DB  0x1,0x0
_tbl16_G101:
	.DB  0x0,0x10,0x0,0x1,0x10,0x0,0x1,0x0

_0x3:
	.DB  0x7C
_0x4:
	.DB  0x1,0x0,0x2,0x0,0x3,0x0,0x4,0x0
	.DB  0x5,0x0,0x6,0x0,0x7,0x0,0x8
_0x5:
	.DB  0x2
_0x6:
	.DB  0x1
_0xAF:
	.DB  0x3C,0x0,0x3E,0x0,0x0,0x0

__GLOBAL_INI_TBL:
	.DW  0x06
	.DW  0x04
	.DW  _0xAF*2

_0xFFFFFFFF:
	.DW  0

__RESET:
	CLI
	CLR  R30
	OUT  EECR,R30

;INTERRUPT VECTORS ARE PLACED
;AT THE START OF FLASH
	LDI  R31,1
	OUT  GICR,R31
	OUT  GICR,R30
	OUT  MCUCR,R30

;DISABLE WATCHDOG
	LDI  R31,0x18
	OUT  WDTCR,R31
	OUT  WDTCR,R30

;CLEAR R2-R14
	LDI  R24,(14-2)+1
	LDI  R26,2
	CLR  R27
__CLEAR_REG:
	ST   X+,R30
	DEC  R24
	BRNE __CLEAR_REG

;CLEAR SRAM
	LDI  R24,LOW(__CLEAR_SRAM_SIZE)
	LDI  R25,HIGH(__CLEAR_SRAM_SIZE)
	LDI  R26,__SRAM_START
__CLEAR_SRAM:
	ST   X+,R30
	SBIW R24,1
	BRNE __CLEAR_SRAM

;GLOBAL VARIABLES INITIALIZATION
	LDI  R30,LOW(__GLOBAL_INI_TBL*2)
	LDI  R31,HIGH(__GLOBAL_INI_TBL*2)
__GLOBAL_INI_NEXT:
	LPM  R24,Z+
	LPM  R25,Z+
	SBIW R24,0
	BREQ __GLOBAL_INI_END
	LPM  R26,Z+
	LPM  R27,Z+
	LPM  R0,Z+
	LPM  R1,Z+
	MOVW R22,R30
	MOVW R30,R0
__GLOBAL_INI_LOOP:
	LPM  R0,Z+
	ST   X+,R0
	SBIW R24,1
	BRNE __GLOBAL_INI_LOOP
	MOVW R30,R22
	RJMP __GLOBAL_INI_NEXT
__GLOBAL_INI_END:

;HARDWARE STACK POINTER INITIALIZATION
	LDI  R30,LOW(__SRAM_END-__HEAP_SIZE)
	OUT  SPL,R30
	LDI  R30,HIGH(__SRAM_END-__HEAP_SIZE)
	OUT  SPH,R30

;DATA STACK POINTER INITIALIZATION
	LDI  R28,LOW(__SRAM_START+__DSTACK_SIZE)
	LDI  R29,HIGH(__SRAM_START+__DSTACK_SIZE)

	RJMP _main

	.ESEG
	.ORG 0

	.DSEG
	.ORG 0x160

	.CSEG
;/*****************************************************
;This program was produced by the
;CodeWizardAVR V2.05.0 Professional
;Automatic Program Generator
;� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com
;
;Project  : YUME 2016 Rangefinder Controller
;Version  : Ver.1.0
;Date     : Tuesday, February 24th 2016
;Author   : Ryan
;Division : Intelligent Legged Fire Fighting Robot Division
;Company  : University of Brawijaya Robotics Team
;Comments:
;
;
;Chip type               : ATmega8
;Program type            : Application
;AVR Core Clock frequency: 16.000000 MHz
;Memory model            : Small
;External RAM size       : 0
;Data Stack size         : 256
;*****************************************************/
;
;#include <mega8.h>
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
;#include <delay.h>
;#include <sleep.h>
;
;// Standard Input/Output functions
;#include <stdio.h>
;#include <sleep.h>
;
;//MACRO
;#define  TIM1_OFF    TCCR1B=0x00
;#define  TIM1_ON     TCCR1B=0x0B
;#define  TIM1_RESET  TCNT1=0x0000
;#define  UDRE 5
;
;//OLD CONFIG WITHOUT SHARP INFRARED RANGER
;//#define PING_LEFT        0
;//#define PING_ASKEW_LEFT  1
;//#define PING_FRONT       2
;//#define PING_ASKEW_RIGHT 3
;//#define PING_RIGHT       4
;//#define PING_REAR        5
;//#define PING_REAR_LEFT   6
;//#define PING_REAR_RIGHT  7
;
;#define PING_LEFT        3
;#define PING_ASKEW_LEFT  4
;#define PING_FRONT       5
;#define PING_ASKEW_RIGHT 6
;#define PING_RIGHT       7
;
;//SHARP IR
;#define SHARP_FRONT     0
;#define SHARP_LEFT      1
;#define SHARP_RIGHT     2
;
;unsigned int COMMAND_FLAG_A = 0x3C;
;unsigned int COMMAND_FLAG_B = 0x3E;
;const unsigned int COMMAND_COMPLETED = 0x7C;

	.DSEG
;
;//GLOBAL VARIABLE
;char flag=0,schedule=0;
;int eksekusi;
;
;unsigned int distance[8]={0,0,0,0,0,0,0,0};
;unsigned int TEST[8]={1,2,3,4,5,6,7,8};
;//char x=0;
;int baud_mode;
;
;//UART SPEED CONFIG VARIABLES
;const int DEBUG_MODE = 2;
;const int ROBOT_MODE = 1;
;
;
;
;
;//Sharp IR Data
;unsigned int ADC_Value;
;float SHARP_Vo;
;unsigned int SHARP_DIST[8]={0,0,0,0,0,0,0,0};
;
;unsigned int SHARP_TEMP[5]={0,0,0,0,0};
;
;//FUNCTION PROTOTYPE
;void YUME_SystemInit(void);
;void UART_Speed_Config(int mode);
;void Ping_Scan(int CHANNEL);
;void Send_UART(unsigned char DATA);
;void SHARP_SCAN (unsigned int CHANNEL);
;
;// Timer1 output compare A interrupt service routine
;interrupt [TIM1_COMPA] void timer1_compa_isr(void)
; 0000 0060 {

	.CSEG
_timer1_compa_isr:
	ST   -Y,R30
; 0000 0061     // Place your code here
; 0000 0062     schedule=1;
	LDI  R30,LOW(1)
	MOV  R8,R30
; 0000 0063 }
	RJMP _0xAE
;
;// Timer1 output compare B interrupt service routine
;interrupt [TIM1_COMPB] void timer1_compb_isr(void)
; 0000 0067 {
_timer1_compb_isr:
	ST   -Y,R30
; 0000 0068     // Place your code here
; 0000 0069     flag=1;
	LDI  R30,LOW(1)
	MOV  R9,R30
; 0000 006A 
; 0000 006B }
_0xAE:
	LD   R30,Y+
	RETI
;
;
;#define ADC_VREF_TYPE 0x60
;
;// Read the 8 most significant bits
;// of the AD conversion result
;unsigned char read_adc(unsigned char adc_input)
; 0000 0073 {
_read_adc:
; 0000 0074 ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
;	adc_input -> Y+0
	LD   R30,Y
	ORI  R30,LOW(0x60)
	OUT  0x7,R30
; 0000 0075 // Delay needed for the stabilization of the ADC input voltage
; 0000 0076 delay_us(10);
	__DELAY_USB 53
; 0000 0077 // Start the AD conversion
; 0000 0078 ADCSRA|=0x40;
	SBI  0x6,6
; 0000 0079 // Wait for the AD conversion to complete
; 0000 007A while ((ADCSRA & 0x10)==0);
_0x7:
	SBIS 0x6,4
	RJMP _0x7
; 0000 007B ADCSRA|=0x10;
	SBI  0x6,4
; 0000 007C return ADCH;
	IN   R30,0x5
	RJMP _0x2080001
; 0000 007D }
;
;
;void main(void)
; 0000 0081 {
_main:
; 0000 0082     YUME_SystemInit();
	RCALL _YUME_SystemInit
; 0000 0083     TIM1_OFF;
	LDI  R30,LOW(0)
	RCALL SUBOPT_0x0
; 0000 0084     TIM1_RESET;
; 0000 0085     PORTD.6=1;
	SBI  0x12,6
; 0000 0086     PORTD.7=0;
	CBI  0x12,7
; 0000 0087     UART_Speed_Config(DEBUG_MODE);
	RCALL SUBOPT_0x1
	RCALL _UART_Speed_Config
; 0000 0088     delay_ms(200);
	LDI  R30,LOW(200)
	LDI  R31,HIGH(200)
	RCALL SUBOPT_0x2
	RCALL _delay_ms
; 0000 0089 
; 0000 008A     // Global enable interrupts
; 0000 008B     #asm("sei") //meaning -> asm= assembler | sei= set enable interrupt
	sei
; 0000 008C 
; 0000 008D while (1)
_0xE:
; 0000 008E       {
; 0000 008F //            SHARP_DIST[0]=read_adc(0);
; 0000 0090 //
; 0000 0091 //            SHARP_Vo= (float)SHARP_DIST[0]/51;
; 0000 0092 ////            printf("SHARP: %d \r",(int) Vo);
; 0000 0093 //
; 0000 0094 //            SHARP_DIST[1]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
; 0000 0095 //
; 0000 0096 //            printf("SHARP: %d \r",(int) SHARP_DIST[1]);
; 0000 0097 //
; 0000 0098 //            SHARP_SCAN(SHARP_FRONT);
; 0000 0099 //            printf("SHARP: %d \r",SHARP_DIST[SHARP_FRONT]);
; 0000 009A 
; 0000 009B 
; 0000 009C //            //Place your code here
; 0000 009D             Send_UART(COMMAND_FLAG_A);
	ST   -Y,R4
	RCALL _Send_UART
; 0000 009E             Send_UART(COMMAND_FLAG_B);
	ST   -Y,R6
	RCALL _Send_UART
; 0000 009F 
; 0000 00A0             Ping_Scan(PING_LEFT); Send_UART(distance[PING_LEFT]);
	RCALL SUBOPT_0x3
	RCALL SUBOPT_0x4
	__GETB1MN _distance,6
	RCALL SUBOPT_0x5
; 0000 00A1             Ping_Scan(PING_RIGHT);Send_UART(distance[PING_RIGHT]);
	LDI  R30,LOW(7)
	LDI  R31,HIGH(7)
	RCALL SUBOPT_0x4
	__GETB1MN _distance,14
	RCALL SUBOPT_0x5
; 0000 00A2             Ping_Scan(PING_FRONT);Send_UART(distance[PING_FRONT]);
	LDI  R30,LOW(5)
	LDI  R31,HIGH(5)
	RCALL SUBOPT_0x4
	__GETB1MN _distance,10
	RCALL SUBOPT_0x5
; 0000 00A3 
; 0000 00A4             //Ping_Scan(PING_REAR);Send_UART(distance[PING_REAR]);
; 0000 00A5             SHARP_SCAN(SHARP_FRONT); Send_UART(SHARP_DIST[SHARP_FRONT]);
	LDI  R30,LOW(0)
	LDI  R31,HIGH(0)
	RCALL SUBOPT_0x2
	RCALL _SHARP_SCAN
	LDS  R30,_SHARP_DIST
	RCALL SUBOPT_0x5
; 0000 00A6 
; 0000 00A7             Ping_Scan(PING_ASKEW_LEFT);Send_UART(distance[PING_ASKEW_LEFT]);
	LDI  R30,LOW(4)
	LDI  R31,HIGH(4)
	RCALL SUBOPT_0x4
	__GETB1MN _distance,8
	RCALL SUBOPT_0x5
; 0000 00A8             Ping_Scan(PING_ASKEW_RIGHT);Send_UART(distance[PING_ASKEW_RIGHT]);
	LDI  R30,LOW(6)
	LDI  R31,HIGH(6)
	RCALL SUBOPT_0x4
	__GETB1MN _distance,12
	RCALL SUBOPT_0x5
; 0000 00A9 
; 0000 00AA 
; 0000 00AB             SHARP_SCAN(SHARP_LEFT); Send_UART(SHARP_DIST[SHARP_LEFT]);
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	RCALL SUBOPT_0x2
	RCALL _SHARP_SCAN
	__GETB1MN _SHARP_DIST,2
	RCALL SUBOPT_0x5
; 0000 00AC             SHARP_SCAN(SHARP_RIGHT); Send_UART(SHARP_DIST[SHARP_RIGHT]);
	RCALL SUBOPT_0x1
	RCALL _SHARP_SCAN
	__GETB1MN _SHARP_DIST,4
	RCALL SUBOPT_0x5
; 0000 00AD 
; 0000 00AE 
; 0000 00AF 
; 0000 00B0 //            Ping_Scan(PING_REAR_LEFT);Send_UART(distance[PING_REAR_LEFT]);
; 0000 00B1 //            Ping_Scan(PING_REAR_RIGHT);Send_UART(distance[PING_REAR_RIGHT]);
; 0000 00B2 
; 0000 00B3       }
	RJMP _0xE
; 0000 00B4 }
_0x11:
	RJMP _0x11
;
;void YUME_SystemInit(void)
; 0000 00B7 {
_YUME_SystemInit:
; 0000 00B8     // Input/Output Ports initialization
; 0000 00B9     // Port B initialization
; 0000 00BA     // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
; 0000 00BB     // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
; 0000 00BC     PORTB=0x00;
	LDI  R30,LOW(0)
	OUT  0x18,R30
; 0000 00BD     DDRB=0x00;
	OUT  0x17,R30
; 0000 00BE 
; 0000 00BF     // Port C initialization
; 0000 00C0     // Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
; 0000 00C1     // State6=T State5=T State4=T State3=T State2=T State1=T State0=T
; 0000 00C2     PORTC=0x00;
	OUT  0x15,R30
; 0000 00C3     DDRC=0x00;
	OUT  0x14,R30
; 0000 00C4 
; 0000 00C5     // Port D initialization
; 0000 00C6     // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
; 0000 00C7     // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
; 0000 00C8     PORTD=0x00;
	OUT  0x12,R30
; 0000 00C9     DDRD=0x00;
	OUT  0x11,R30
; 0000 00CA 
; 0000 00CB     // Timer/Counter 0 initialization
; 0000 00CC     // Clock source: System Clock
; 0000 00CD     // Clock value: Timer 0 Stopped
; 0000 00CE     TCCR0=0x00;
	OUT  0x33,R30
; 0000 00CF     TCNT0=0x00;
	OUT  0x32,R30
; 0000 00D0 
; 0000 00D1     // Timer/Counter 1 initialization
; 0000 00D2     // Clock source: System Clock
; 0000 00D3     // Clock value: 250.000 kHz
; 0000 00D4     // Mode: CTC top=OCR1A
; 0000 00D5     // OC1A output: Discon.
; 0000 00D6     // OC1B output: Discon.
; 0000 00D7     // Noise Canceler: Off
; 0000 00D8     // Input Capture on Falling Edge
; 0000 00D9     // Timer1 Overflow Interrupt: Off
; 0000 00DA     // Input Capture Interrupt: Off
; 0000 00DB     // Compare A Match Interrupt: On
; 0000 00DC     // Compare B Match Interrupt: On
; 0000 00DD     TCCR1A=0x00;
	OUT  0x2F,R30
; 0000 00DE     TCCR1B=0x0B;
	LDI  R30,LOW(11)
	OUT  0x2E,R30
; 0000 00DF     TCNT1H=0x00;
	LDI  R30,LOW(0)
	OUT  0x2D,R30
; 0000 00E0     TCNT1L=0x00;
	OUT  0x2C,R30
; 0000 00E1     ICR1H=0x00;
	OUT  0x27,R30
; 0000 00E2     ICR1L=0x00;
	OUT  0x26,R30
; 0000 00E3     OCR1AH=0x09;
	LDI  R30,LOW(9)
	OUT  0x2B,R30
; 0000 00E4     OCR1AL=0xC4;
	LDI  R30,LOW(196)
	OUT  0x2A,R30
; 0000 00E5     OCR1BH=0x07;
	LDI  R30,LOW(7)
	OUT  0x29,R30
; 0000 00E6     OCR1BL=0xD0;
	LDI  R30,LOW(208)
	OUT  0x28,R30
; 0000 00E7 
; 0000 00E8     // Timer/Counter 2 initialization
; 0000 00E9     // Clock source: System Clock
; 0000 00EA     // Clock value: Timer2 Stopped
; 0000 00EB     // Mode: Normal top=0xFF
; 0000 00EC     // OC2 output: Disconnected
; 0000 00ED     ASSR=0x00;
	LDI  R30,LOW(0)
	OUT  0x22,R30
; 0000 00EE     TCCR2=0x00;
	OUT  0x25,R30
; 0000 00EF     TCNT2=0x00;
	OUT  0x24,R30
; 0000 00F0     OCR2=0x00;
	OUT  0x23,R30
; 0000 00F1 
; 0000 00F2     // External Interrupt(s) initialization
; 0000 00F3     // INT0: Off
; 0000 00F4     // INT1: Off
; 0000 00F5     MCUCR=0x00;
	OUT  0x35,R30
; 0000 00F6 
; 0000 00F7     // Timer(s)/Counter(s) Interrupt(s) initialization
; 0000 00F8     TIMSK=0x18;
	LDI  R30,LOW(24)
	OUT  0x39,R30
; 0000 00F9 
; 0000 00FA     // USART initialization
; 0000 00FB     // Communication Parameters: 8 Data, 1 Stop, No Parity
; 0000 00FC     // USART Receiver: Off
; 0000 00FD     // USART Transmitter: On
; 0000 00FE     // USART Mode: Asynchronous
; 0000 00FF     // USART Baud Rate: 9600
; 0000 0100     UCSRA=0x00;
	LDI  R30,LOW(0)
	OUT  0xB,R30
; 0000 0101     UCSRB=0x08;
	LDI  R30,LOW(8)
	OUT  0xA,R30
; 0000 0102     UCSRC=0x86;
	LDI  R30,LOW(134)
	OUT  0x20,R30
; 0000 0103     UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 0104     UBRRL=0x67;
	LDI  R30,LOW(103)
	OUT  0x9,R30
; 0000 0105 
; 0000 0106     // Analog Comparator initialization
; 0000 0107     // Analog Comparator: Off
; 0000 0108     // Analog Comparator Input Capture by Timer/Counter 1: Off
; 0000 0109     ACSR=0x80;
	LDI  R30,LOW(128)
	OUT  0x8,R30
; 0000 010A     SFIOR=0x00;
	LDI  R30,LOW(0)
	OUT  0x30,R30
; 0000 010B 
; 0000 010C     // ADC initialization
; 0000 010D     // ADC Clock frequency: 500.000 kHz
; 0000 010E     // ADC Voltage Reference: AVCC pin
; 0000 010F     // Only the 8 most significant bits of
; 0000 0110     // the AD conversion result are used
; 0000 0111     ADMUX=ADC_VREF_TYPE & 0xff;
	LDI  R30,LOW(96)
	OUT  0x7,R30
; 0000 0112     ADCSRA=0x85;
	LDI  R30,LOW(133)
	OUT  0x6,R30
; 0000 0113 
; 0000 0114     // SPI initialization
; 0000 0115     // SPI disabled
; 0000 0116     SPCR=0x00;
	LDI  R30,LOW(0)
	OUT  0xD,R30
; 0000 0117 
; 0000 0118     // TWI initialization
; 0000 0119     // TWI disabled
; 0000 011A     TWCR=0x00;
	OUT  0x36,R30
; 0000 011B }
	RET
;
;void UART_Speed_Config(int mode)
; 0000 011E {
_UART_Speed_Config:
; 0000 011F     //BAUD RATE SELECT INITIALIZATION
; 0000 0120     if (PINB.3==0) baud_mode=1;
;	mode -> Y+0
	SBIC 0x16,3
	RJMP _0x12
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	RJMP _0xAB
; 0000 0121     else if (PINB.3==1) baud_mode=2;
_0x12:
	SBIS 0x16,3
	RJMP _0x14
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
_0xAB:
	MOVW R12,R30
; 0000 0122 
; 0000 0123     switch(mode)
_0x14:
	LD   R30,Y
	LDD  R31,Y+1
; 0000 0124     {
; 0000 0125         case 1:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0x18
; 0000 0126             {
; 0000 0127                 UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 0128                 UBRRL=0x00;
	RJMP _0xAC
; 0000 0129             }break;
; 0000 012A         case 2:
_0x18:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x17
; 0000 012B             {
; 0000 012C                 UBRRH=0x00;
	LDI  R30,LOW(0)
	OUT  0x20,R30
; 0000 012D                 UBRRL=0x67;
	LDI  R30,LOW(103)
_0xAC:
	OUT  0x9,R30
; 0000 012E             }break;
; 0000 012F 
; 0000 0130     }
_0x17:
; 0000 0131 
; 0000 0132     #asm("cli")
	cli
; 0000 0133     //if(PIND.3==0)    operational 1Mbps
; 0000 0134      //   {
; 0000 0135      //       UBRRH=0x00;
; 0000 0136       //      UBRRL=0x00;
; 0000 0137       //  }
; 0000 0138     //else   //9600bps for debug purpose
; 0000 0139         //{
; 0000 013A             //UBRRH=0x00;
; 0000 013B             //UBRRL=0x67;
; 0000 013C         //}
; 0000 013D     #asm("sei")
	sei
; 0000 013E }
	RJMP _0x2080002
;void Ping_Scan(int CHANNEL)
; 0000 0140 {
_Ping_Scan:
; 0000 0141     PORTD.6 = ~PORTD.6;
;	CHANNEL -> Y+0
	SBIS 0x12,6
	RJMP _0x1A
	CBI  0x12,6
	RJMP _0x1B
_0x1A:
	SBI  0x12,6
_0x1B:
; 0000 0142     PORTD.7 = ~PORTD.7;
	SBIS 0x12,7
	RJMP _0x1C
	CBI  0x12,7
	RJMP _0x1D
_0x1C:
	SBI  0x12,7
_0x1D:
; 0000 0143 
; 0000 0144     TIM1_OFF;
	LDI  R30,LOW(0)
	OUT  0x2E,R30
; 0000 0145     flag=0;
	CLR  R9
; 0000 0146     schedule=0;
	CLR  R8
; 0000 0147     TIM1_RESET;
	LDI  R30,LOW(0)
	LDI  R31,HIGH(0)
	OUT  0x2C+1,R31
	OUT  0x2C,R30
; 0000 0148 
; 0000 0149     PORTB&=0x00;
	IN   R30,0x18
	ANDI R30,LOW(0x0)
	OUT  0x18,R30
; 0000 014A     DDRB&=0x00;
	IN   R30,0x17
	ANDI R30,LOW(0x0)
	OUT  0x17,R30
; 0000 014B     PORTC&=0x00;
	IN   R30,0x15
	ANDI R30,LOW(0x0)
	OUT  0x15,R30
; 0000 014C     DDRC&=0x00;
	IN   R30,0x14
	ANDI R30,LOW(0x0)
	OUT  0x14,R30
; 0000 014D 
; 0000 014E     TIM1_ON;
	LDI  R30,LOW(11)
	OUT  0x2E,R30
; 0000 014F 
; 0000 0150     switch(CHANNEL)
	LD   R30,Y
	LDD  R31,Y+1
; 0000 0151     {
; 0000 0152 //        case 0:
; 0000 0153 //                {
; 0000 0154 //                    DDRC.0=1;PORTC.0=1;delay_us(5);PORTC.0=0;
; 0000 0155 //                    DDRC.0=0;delay_us(4);
; 0000 0156 //
; 0000 0157 //                    while(PINC.0==1 && flag==0){};
; 0000 0158 //                    while(PINC.0==0 && flag==0){}; TIM1_ON; TIM1_RESET;
; 0000 0159 //                    while(PINC.0==1 && flag==0){}; TIM1_OFF;
; 0000 015A //
; 0000 015B //                }break;
; 0000 015C //
; 0000 015D //        case 1:
; 0000 015E //                {
; 0000 015F //                    DDRC.1=1;PORTC.1=1;delay_us(5);PORTC.1=0;
; 0000 0160 //                    DDRC.1=0;delay_us(4);
; 0000 0161 //
; 0000 0162 //                    while(PINC.1==1 && flag==0){};
; 0000 0163 //                    while(PINC.1==0 && flag==0){}; TIM1_ON; TIM1_RESET;
; 0000 0164 //                    while(PINC.1==1 && flag==0){}; TIM1_OFF;
; 0000 0165 //
; 0000 0166 //                }break;
; 0000 0167 //        case 2:
; 0000 0168 //                {
; 0000 0169 //                    DDRC.2=1;PORTC.2=1;delay_us(5);PORTC.2=0;
; 0000 016A //                    DDRC.2=0;delay_us(4);
; 0000 016B //
; 0000 016C //                    while(PINC.2==1 && flag==0){};
; 0000 016D //                    while(PINC.2==0 && flag==0){}; TIM1_ON; TIM1_RESET;
; 0000 016E //                    while(PINC.2==1 && flag==0){}; TIM1_OFF;
; 0000 016F //
; 0000 0170 //                }break;
; 0000 0171         case 3:
	CPI  R30,LOW(0x3)
	LDI  R26,HIGH(0x3)
	CPC  R31,R26
	BRNE _0x21
; 0000 0172                 {
; 0000 0173                     DDRC.3=1;PORTC.3=1;delay_us(5);PORTC.3=0;
	SBI  0x14,3
	SBI  0x15,3
	RCALL SUBOPT_0x6
	CBI  0x15,3
; 0000 0174                     DDRC.3=0;delay_us(4);
	CBI  0x14,3
	RCALL SUBOPT_0x7
; 0000 0175 
; 0000 0176                     while(PINC.3==1 && flag==0){};
_0x2A:
	SBIS 0x13,3
	RJMP _0x2D
	RCALL SUBOPT_0x8
	BREQ _0x2E
_0x2D:
	RJMP _0x2C
_0x2E:
	RJMP _0x2A
_0x2C:
; 0000 0177                     while(PINC.3==0 && flag==0){}; TIM1_ON; TIM1_RESET;
_0x2F:
	LDI  R26,0
	SBIC 0x13,3
	LDI  R26,1
	CPI  R26,LOW(0x0)
	BRNE _0x32
	RCALL SUBOPT_0x8
	BREQ _0x33
_0x32:
	RJMP _0x31
_0x33:
	RJMP _0x2F
_0x31:
	RCALL SUBOPT_0x9
; 0000 0178                     while(PINC.3==1 && flag==0){}; TIM1_OFF;
_0x34:
	SBIS 0x13,3
	RJMP _0x37
	RCALL SUBOPT_0x8
	BREQ _0x38
_0x37:
	RJMP _0x36
_0x38:
	RJMP _0x34
_0x36:
	RJMP _0xAD
; 0000 0179 
; 0000 017A                 }break;
; 0000 017B         case 4:
_0x21:
	CPI  R30,LOW(0x4)
	LDI  R26,HIGH(0x4)
	CPC  R31,R26
	BRNE _0x39
; 0000 017C                 {
; 0000 017D                     DDRC.4=1;PORTC.4=1;delay_us(5);PORTC.4=0;
	SBI  0x14,4
	SBI  0x15,4
	RCALL SUBOPT_0x6
	CBI  0x15,4
; 0000 017E                     DDRC.4=0;delay_us(4);
	CBI  0x14,4
	RCALL SUBOPT_0x7
; 0000 017F 
; 0000 0180                     while(PINC.4==1 && flag==0){};
_0x42:
	SBIS 0x13,4
	RJMP _0x45
	RCALL SUBOPT_0x8
	BREQ _0x46
_0x45:
	RJMP _0x44
_0x46:
	RJMP _0x42
_0x44:
; 0000 0181                     while(PINC.4==0 && flag==0){}; TIM1_ON; TIM1_RESET;
_0x47:
	LDI  R26,0
	SBIC 0x13,4
	LDI  R26,1
	CPI  R26,LOW(0x0)
	BRNE _0x4A
	RCALL SUBOPT_0x8
	BREQ _0x4B
_0x4A:
	RJMP _0x49
_0x4B:
	RJMP _0x47
_0x49:
	RCALL SUBOPT_0x9
; 0000 0182                     while(PINC.4==1 && flag==0){}; TIM1_OFF;
_0x4C:
	SBIS 0x13,4
	RJMP _0x4F
	RCALL SUBOPT_0x8
	BREQ _0x50
_0x4F:
	RJMP _0x4E
_0x50:
	RJMP _0x4C
_0x4E:
	RJMP _0xAD
; 0000 0183 
; 0000 0184                 }break;
; 0000 0185         case 5:
_0x39:
	CPI  R30,LOW(0x5)
	LDI  R26,HIGH(0x5)
	CPC  R31,R26
	BRNE _0x51
; 0000 0186                 {
; 0000 0187                     DDRC.5=1;PORTC.5=1;delay_us(5);PORTC.5=0;
	SBI  0x14,5
	SBI  0x15,5
	RCALL SUBOPT_0x6
	CBI  0x15,5
; 0000 0188                     DDRC.5=0;delay_us(4);
	CBI  0x14,5
	RCALL SUBOPT_0x7
; 0000 0189 
; 0000 018A                     while(PINC.5==1 && flag==0){};
_0x5A:
	SBIS 0x13,5
	RJMP _0x5D
	RCALL SUBOPT_0x8
	BREQ _0x5E
_0x5D:
	RJMP _0x5C
_0x5E:
	RJMP _0x5A
_0x5C:
; 0000 018B                     while(PINC.5==0 && flag==0){}; TIM1_ON; TIM1_RESET;
_0x5F:
	LDI  R26,0
	SBIC 0x13,5
	LDI  R26,1
	CPI  R26,LOW(0x0)
	BRNE _0x62
	RCALL SUBOPT_0x8
	BREQ _0x63
_0x62:
	RJMP _0x61
_0x63:
	RJMP _0x5F
_0x61:
	RCALL SUBOPT_0x9
; 0000 018C                     while(PINC.5==1 && flag==0){}; TIM1_OFF;
_0x64:
	SBIS 0x13,5
	RJMP _0x67
	RCALL SUBOPT_0x8
	BREQ _0x68
_0x67:
	RJMP _0x66
_0x68:
	RJMP _0x64
_0x66:
	RJMP _0xAD
; 0000 018D 
; 0000 018E                 }break;
; 0000 018F         case 6:
_0x51:
	CPI  R30,LOW(0x6)
	LDI  R26,HIGH(0x6)
	CPC  R31,R26
	BRNE _0x69
; 0000 0190                 {
; 0000 0191                     DDRB.0=1;PORTB.0=1;delay_us(5);PORTB.0=0;
	SBI  0x17,0
	SBI  0x18,0
	RCALL SUBOPT_0x6
	CBI  0x18,0
; 0000 0192                     DDRB.0=0;delay_us(4);
	CBI  0x17,0
	RCALL SUBOPT_0x7
; 0000 0193 
; 0000 0194                     while(PINB.0==1 && flag==0){};
_0x72:
	SBIS 0x16,0
	RJMP _0x75
	RCALL SUBOPT_0x8
	BREQ _0x76
_0x75:
	RJMP _0x74
_0x76:
	RJMP _0x72
_0x74:
; 0000 0195                     while(PINB.0==0 && flag==0){}; TIM1_ON; TIM1_RESET;
_0x77:
	LDI  R26,0
	SBIC 0x16,0
	LDI  R26,1
	CPI  R26,LOW(0x0)
	BRNE _0x7A
	RCALL SUBOPT_0x8
	BREQ _0x7B
_0x7A:
	RJMP _0x79
_0x7B:
	RJMP _0x77
_0x79:
	RCALL SUBOPT_0x9
; 0000 0196                     while(PINB.0==1 && flag==0){}; TIM1_OFF;
_0x7C:
	SBIS 0x16,0
	RJMP _0x7F
	RCALL SUBOPT_0x8
	BREQ _0x80
_0x7F:
	RJMP _0x7E
_0x80:
	RJMP _0x7C
_0x7E:
	RJMP _0xAD
; 0000 0197 
; 0000 0198                 }break;
; 0000 0199         case 7:
_0x69:
	CPI  R30,LOW(0x7)
	LDI  R26,HIGH(0x7)
	CPC  R31,R26
	BRNE _0x20
; 0000 019A                 {
; 0000 019B                     DDRB.1=1;PORTB.1=1;delay_us(5);PORTB.1=0;
	SBI  0x17,1
	SBI  0x18,1
	RCALL SUBOPT_0x6
	CBI  0x18,1
; 0000 019C                     DDRB.1=0;delay_us(4);
	CBI  0x17,1
	RCALL SUBOPT_0x7
; 0000 019D 
; 0000 019E                     while(PINB.1==1 && flag==0){};
_0x8A:
	SBIS 0x16,1
	RJMP _0x8D
	RCALL SUBOPT_0x8
	BREQ _0x8E
_0x8D:
	RJMP _0x8C
_0x8E:
	RJMP _0x8A
_0x8C:
; 0000 019F                     while(PINB.1==0 && flag==0){}; TIM1_ON; TIM1_RESET;
_0x8F:
	LDI  R26,0
	SBIC 0x16,1
	LDI  R26,1
	CPI  R26,LOW(0x0)
	BRNE _0x92
	RCALL SUBOPT_0x8
	BREQ _0x93
_0x92:
	RJMP _0x91
_0x93:
	RJMP _0x8F
_0x91:
	RCALL SUBOPT_0x9
; 0000 01A0                     while(PINB.1==1 && flag==0){}; TIM1_OFF;
_0x94:
	SBIS 0x16,1
	RJMP _0x97
	RCALL SUBOPT_0x8
	BREQ _0x98
_0x97:
	RJMP _0x96
_0x98:
	RJMP _0x94
_0x96:
_0xAD:
	LDI  R30,LOW(0)
	OUT  0x2E,R30
; 0000 01A1 
; 0000 01A2                 }break;
; 0000 01A3     }
_0x20:
; 0000 01A4 
; 0000 01A5     distance[CHANNEL]=(unsigned int)((344*0.5*100*TCNT1*64)/16000000);
	LD   R30,Y
	LDD  R31,Y+1
	LDI  R26,LOW(_distance)
	LDI  R27,HIGH(_distance)
	RCALL SUBOPT_0xA
	PUSH R31
	PUSH R30
	IN   R30,0x2C
	IN   R31,0x2C+1
	RCALL SUBOPT_0xB
	__GETD2N 0x46866000
	RCALL __MULF12
	__GETD2N 0x42800000
	RCALL SUBOPT_0xC
	__GETD1N 0x4B742400
	RCALL __DIVF21
	RCALL __CFD1U
	POP  R26
	POP  R27
	RCALL SUBOPT_0xD
; 0000 01A6 
; 0000 01A7 
; 0000 01A8 
; 0000 01A9     //printf("TCNT1 Value: %d ",TCNT1);
; 0000 01AA     //Send_UART(distance[CHANNEL]);
; 0000 01AB     //printf("Ping[%d]: %d   ",CHANNEL, distance[CHANNEL]);    // \r -> return (go back to column 1 of current output line)
; 0000 01AC     TIM1_ON;
	LDI  R30,LOW(11)
	OUT  0x2E,R30
; 0000 01AD     //if(schedule==0){idle();}
; 0000 01AE     TIM1_OFF;
	LDI  R30,LOW(0)
	OUT  0x2E,R30
; 0000 01AF }
_0x2080002:
	ADIW R28,2
	RET
;
;
;void Send_UART(unsigned char DATA)
; 0000 01B3 {
_Send_UART:
; 0000 01B4     while(!(UCSRA & (1<<UDRE))){};
;	DATA -> Y+0
_0x99:
	SBIS 0xB,5
	RJMP _0x99
; 0000 01B5     UDR= DATA;
	LD   R30,Y
	OUT  0xC,R30
; 0000 01B6 }
_0x2080001:
	ADIW R28,1
	RET
;
;
;void SHARP_ADC_Read(void)
; 0000 01BA {
; 0000 01BB     ADC_Value= read_adc(0);
; 0000 01BC     SHARP_Vo= ADC_Value/51;
; 0000 01BD }
;
;void SHARP_Calc(unsigned int CHANNEL)
; 0000 01C0 {
; 0000 01C1     //SHARP_DIST[CHANNEL]= (float) ((1/((0.04*SHARP_Vo)-0;
; 0000 01C2 }
;
;
;void SHARP_SCAN (unsigned int CHANNEL)
; 0000 01C6 {
_SHARP_SCAN:
; 0000 01C7     int counter=0;
; 0000 01C8 
; 0000 01C9     ADC_Value=0;
	RCALL __SAVELOCR2
;	CHANNEL -> Y+2
;	counter -> R16,R17
	RCALL SUBOPT_0xE
	LDI  R30,LOW(0)
	STS  _ADC_Value,R30
	STS  _ADC_Value+1,R30
; 0000 01CA     SHARP_Vo=0;
	STS  _SHARP_Vo,R30
	STS  _SHARP_Vo+1,R30
	STS  _SHARP_Vo+2,R30
	STS  _SHARP_Vo+3,R30
; 0000 01CB     SHARP_TEMP[0]=0;
	STS  _SHARP_TEMP,R30
	STS  _SHARP_TEMP+1,R30
; 0000 01CC     SHARP_TEMP[1]=0;
	__POINTW1MN _SHARP_TEMP,2
	RCALL SUBOPT_0xF
; 0000 01CD     SHARP_TEMP[2]=0;
	__POINTW1MN _SHARP_TEMP,4
	RCALL SUBOPT_0xF
; 0000 01CE     SHARP_TEMP[3]=0;
	__POINTW1MN _SHARP_TEMP,6
	RCALL SUBOPT_0xF
; 0000 01CF     SHARP_TEMP[4]=0;
	__POINTW1MN _SHARP_TEMP,8
	RCALL SUBOPT_0xF
; 0000 01D0 
; 0000 01D1     switch (CHANNEL)
	LDD  R30,Y+2
	LDD  R31,Y+2+1
; 0000 01D2     {
; 0000 01D3         case 0:
	SBIW R30,0
	BRNE _0x9F
; 0000 01D4                 {
; 0000 01D5                      for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0xE
_0xA1:
	RCALL SUBOPT_0x10
	BRGE _0xA2
; 0000 01D6                      {
; 0000 01D7                         ADC_Value = read_adc(0);
	LDI  R30,LOW(0)
	RCALL SUBOPT_0x11
; 0000 01D8                         SHARP_Vo  = (float)ADC_Value/51;
; 0000 01D9                         SHARP_TEMP[counter]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
	PUSH R31
	PUSH R30
	RCALL SUBOPT_0x12
	RCALL SUBOPT_0x13
	POP  R26
	POP  R27
	RCALL __CFD1U
	RCALL SUBOPT_0xD
; 0000 01DA                      }
	__ADDWRN 16,17,1
	RJMP _0xA1
_0xA2:
; 0000 01DB 
; 0000 01DC                      SHARP_DIST[SHARP_FRONT]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/3;
	RCALL SUBOPT_0x14
	STS  _SHARP_DIST,R30
	STS  _SHARP_DIST+1,R31
; 0000 01DD 
; 0000 01DE //                     ADC_Value = read_adc(0);
; 0000 01DF //                     SHARP_Vo  = (float)ADC_Value/51;
; 0000 01E0 //                     SHARP_DIST[SHARP_FRONT]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
; 0000 01E1                 }break;
	RJMP _0x9E
; 0000 01E2 
; 0000 01E3         case 1:
_0x9F:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0xA3
; 0000 01E4                 {
; 0000 01E5                      for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0xE
_0xA5:
	RCALL SUBOPT_0x10
	BRGE _0xA6
; 0000 01E6                      {
; 0000 01E7                         ADC_Value = read_adc(1);
	LDI  R30,LOW(1)
	RCALL SUBOPT_0x11
; 0000 01E8                         SHARP_Vo  = (float)ADC_Value/51;
; 0000 01E9                         SHARP_TEMP[counter]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
	PUSH R31
	PUSH R30
	RCALL SUBOPT_0x12
	RCALL SUBOPT_0x13
	POP  R26
	POP  R27
	RCALL __CFD1U
	RCALL SUBOPT_0xD
; 0000 01EA                      }
	__ADDWRN 16,17,1
	RJMP _0xA5
_0xA6:
; 0000 01EB 
; 0000 01EC                      SHARP_DIST[SHARP_LEFT]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/3;
	RCALL SUBOPT_0x14
	__PUTW1MN _SHARP_DIST,2
; 0000 01ED //                     ADC_Value = read_adc(1);
; 0000 01EE //                     SHARP_Vo  = (float)ADC_Value/51;
; 0000 01EF //                     SHARP_DIST[SHARP_LEFT]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
; 0000 01F0                 }break;
	RJMP _0x9E
; 0000 01F1 
; 0000 01F2         case 2:
_0xA3:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x9E
; 0000 01F3                 {
; 0000 01F4                      for(counter=0;counter<=4;counter++)
	RCALL SUBOPT_0xE
_0xA9:
	RCALL SUBOPT_0x10
	BRGE _0xAA
; 0000 01F5                      {
; 0000 01F6                         ADC_Value = read_adc(2);
	LDI  R30,LOW(2)
	RCALL SUBOPT_0x11
; 0000 01F7                         SHARP_Vo  = (float)ADC_Value/51;
; 0000 01F8                         SHARP_TEMP[counter]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
	PUSH R31
	PUSH R30
	RCALL SUBOPT_0x12
	RCALL SUBOPT_0x13
	POP  R26
	POP  R27
	RCALL __CFD1U
	RCALL SUBOPT_0xD
; 0000 01F9                      }
	__ADDWRN 16,17,1
	RJMP _0xA9
_0xAA:
; 0000 01FA 
; 0000 01FB                      SHARP_DIST[SHARP_RIGHT]= (SHARP_TEMP[0]+SHARP_TEMP[1]+SHARP_TEMP[2]+SHARP_TEMP[3]+SHARP_TEMP[4])/3;
	RCALL SUBOPT_0x14
	__PUTW1MN _SHARP_DIST,4
; 0000 01FC 
; 0000 01FD //                     ADC_Value = read_adc(2);
; 0000 01FE //                     SHARP_Vo  = (float)ADC_Value/51;
; 0000 01FF //                     SHARP_DIST[SHARP_RIGHT]= (float)((1/((0.0821*SHARP_Vo)-0.0042)-0.42));
; 0000 0200                 }break;
; 0000 0201     }
_0x9E:
; 0000 0202 
; 0000 0203 }
	RCALL __LOADLOCR2
	ADIW R28,4
	RET
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif

	.CSEG
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif

	.CSEG

	.CSEG

	.CSEG

	.DSEG
_distance:
	.BYTE 0x10
_ADC_Value:
	.BYTE 0x2
_SHARP_Vo:
	.BYTE 0x4
_SHARP_DIST:
	.BYTE 0x10
_SHARP_TEMP:
	.BYTE 0xA

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:18 WORDS
SUBOPT_0x0:
	OUT  0x2E,R30
	LDI  R30,LOW(0)
	LDI  R31,HIGH(0)
	OUT  0x2C+1,R31
	OUT  0x2C,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x1:
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	ST   -Y,R31
	ST   -Y,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 8 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0x2:
	ST   -Y,R31
	ST   -Y,R30
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x3:
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x4:
	RCALL SUBOPT_0x2
	RJMP _Ping_Scan

;OPTIMIZER ADDED SUBROUTINE, CALLED 8 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0x5:
	ST   -Y,R30
	RJMP _Send_UART

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:6 WORDS
SUBOPT_0x6:
	__DELAY_USB 27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:6 WORDS
SUBOPT_0x7:
	__DELAY_USB 21
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 15 TIMES, CODE SIZE REDUCTION:12 WORDS
SUBOPT_0x8:
	LDI  R30,LOW(0)
	CP   R30,R9
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 5 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x9:
	LDI  R30,LOW(11)
	RJMP SUBOPT_0x0

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0xA:
	LSL  R30
	ROL  R31
	ADD  R30,R26
	ADC  R31,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0xB:
	CLR  R22
	CLR  R23
	RCALL __CDF1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0xC:
	RCALL __MULF12
	MOVW R26,R30
	MOVW R24,R22
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xD:
	ST   X+,R30
	ST   X,R31
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xE:
	__GETWRN 16,17,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:7 WORDS
SUBOPT_0xF:
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	STD  Z+0,R26
	STD  Z+1,R27
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x10:
	__CPWRN 16,17,5
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:62 WORDS
SUBOPT_0x11:
	ST   -Y,R30
	RCALL _read_adc
	LDI  R31,0
	STS  _ADC_Value,R30
	STS  _ADC_Value+1,R31
	RCALL SUBOPT_0xB
	MOVW R26,R30
	MOVW R24,R22
	__GETD1N 0x424C0000
	RCALL __DIVF21
	STS  _SHARP_Vo,R30
	STS  _SHARP_Vo+1,R31
	STS  _SHARP_Vo+2,R22
	STS  _SHARP_Vo+3,R23
	MOVW R30,R16
	LDI  R26,LOW(_SHARP_TEMP)
	LDI  R27,HIGH(_SHARP_TEMP)
	RJMP SUBOPT_0xA

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:22 WORDS
SUBOPT_0x12:
	LDS  R30,_SHARP_Vo
	LDS  R31,_SHARP_Vo+1
	LDS  R22,_SHARP_Vo+2
	LDS  R23,_SHARP_Vo+3
	__GETD2N 0x3DA8240B
	RJMP SUBOPT_0xC

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:34 WORDS
SUBOPT_0x13:
	__GETD1N 0x3B89A027
	RCALL __SWAPD12
	RCALL __SUBF12
	__GETD2N 0x3F800000
	RCALL __DIVF21
	MOVW R26,R30
	MOVW R24,R22
	__GETD1N 0x3ED70A3D
	RCALL __SWAPD12
	RCALL __SUBF12
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:56 WORDS
SUBOPT_0x14:
	__GETW1MN _SHARP_TEMP,2
	LDS  R26,_SHARP_TEMP
	LDS  R27,_SHARP_TEMP+1
	ADD  R26,R30
	ADC  R27,R31
	__GETW1MN _SHARP_TEMP,4
	ADD  R26,R30
	ADC  R27,R31
	__GETW1MN _SHARP_TEMP,6
	ADD  R26,R30
	ADC  R27,R31
	__GETW1MN _SHARP_TEMP,8
	ADD  R26,R30
	ADC  R27,R31
	RCALL SUBOPT_0x3
	RCALL __DIVW21U
	RET


	.CSEG
_delay_ms:
	ld   r30,y+
	ld   r31,y+
	adiw r30,0
	breq __delay_ms1
__delay_ms0:
	__DELAY_USW 0xFA0
	wdr
	sbiw r30,1
	brne __delay_ms0
__delay_ms1:
	ret

__ROUND_REPACK:
	TST  R21
	BRPL __REPACK
	CPI  R21,0x80
	BRNE __ROUND_REPACK0
	SBRS R30,0
	RJMP __REPACK
__ROUND_REPACK0:
	ADIW R30,1
	ADC  R22,R25
	ADC  R23,R25
	BRVS __REPACK1

__REPACK:
	LDI  R21,0x80
	EOR  R21,R23
	BRNE __REPACK0
	PUSH R21
	RJMP __ZERORES
__REPACK0:
	CPI  R21,0xFF
	BREQ __REPACK1
	LSL  R22
	LSL  R0
	ROR  R21
	ROR  R22
	MOV  R23,R21
	RET
__REPACK1:
	PUSH R21
	TST  R0
	BRMI __REPACK2
	RJMP __MAXRES
__REPACK2:
	RJMP __MINRES

__UNPACK:
	LDI  R21,0x80
	MOV  R1,R25
	AND  R1,R21
	LSL  R24
	ROL  R25
	EOR  R25,R21
	LSL  R21
	ROR  R24

__UNPACK1:
	LDI  R21,0x80
	MOV  R0,R23
	AND  R0,R21
	LSL  R22
	ROL  R23
	EOR  R23,R21
	LSL  R21
	ROR  R22
	RET

__CFD1U:
	SET
	RJMP __CFD1U0
__CFD1:
	CLT
__CFD1U0:
	PUSH R21
	RCALL __UNPACK1
	CPI  R23,0x80
	BRLO __CFD10
	CPI  R23,0xFF
	BRCC __CFD10
	RJMP __ZERORES
__CFD10:
	LDI  R21,22
	SUB  R21,R23
	BRPL __CFD11
	NEG  R21
	CPI  R21,8
	BRTC __CFD19
	CPI  R21,9
__CFD19:
	BRLO __CFD17
	SER  R30
	SER  R31
	SER  R22
	LDI  R23,0x7F
	BLD  R23,7
	RJMP __CFD15
__CFD17:
	CLR  R23
	TST  R21
	BREQ __CFD15
__CFD18:
	LSL  R30
	ROL  R31
	ROL  R22
	ROL  R23
	DEC  R21
	BRNE __CFD18
	RJMP __CFD15
__CFD11:
	CLR  R23
__CFD12:
	CPI  R21,8
	BRLO __CFD13
	MOV  R30,R31
	MOV  R31,R22
	MOV  R22,R23
	SUBI R21,8
	RJMP __CFD12
__CFD13:
	TST  R21
	BREQ __CFD15
__CFD14:
	LSR  R23
	ROR  R22
	ROR  R31
	ROR  R30
	DEC  R21
	BRNE __CFD14
__CFD15:
	TST  R0
	BRPL __CFD16
	RCALL __ANEGD1
__CFD16:
	POP  R21
	RET

__CDF1U:
	SET
	RJMP __CDF1U0
__CDF1:
	CLT
__CDF1U0:
	SBIW R30,0
	SBCI R22,0
	SBCI R23,0
	BREQ __CDF10
	CLR  R0
	BRTS __CDF11
	TST  R23
	BRPL __CDF11
	COM  R0
	RCALL __ANEGD1
__CDF11:
	MOV  R1,R23
	LDI  R23,30
	TST  R1
__CDF12:
	BRMI __CDF13
	DEC  R23
	LSL  R30
	ROL  R31
	ROL  R22
	ROL  R1
	RJMP __CDF12
__CDF13:
	MOV  R30,R31
	MOV  R31,R22
	MOV  R22,R1
	PUSH R21
	RCALL __REPACK
	POP  R21
__CDF10:
	RET

__SWAPACC:
	PUSH R20
	MOVW R20,R30
	MOVW R30,R26
	MOVW R26,R20
	MOVW R20,R22
	MOVW R22,R24
	MOVW R24,R20
	MOV  R20,R0
	MOV  R0,R1
	MOV  R1,R20
	POP  R20
	RET

__UADD12:
	ADD  R30,R26
	ADC  R31,R27
	ADC  R22,R24
	RET

__NEGMAN1:
	COM  R30
	COM  R31
	COM  R22
	SUBI R30,-1
	SBCI R31,-1
	SBCI R22,-1
	RET

__SUBF12:
	PUSH R21
	RCALL __UNPACK
	CPI  R25,0x80
	BREQ __ADDF129
	LDI  R21,0x80
	EOR  R1,R21

__ADDF120:
	CPI  R23,0x80
	BREQ __ADDF128
__ADDF121:
	MOV  R21,R23
	SUB  R21,R25
	BRVS __ADDF1211
	BRPL __ADDF122
	RCALL __SWAPACC
	RJMP __ADDF121
__ADDF122:
	CPI  R21,24
	BRLO __ADDF123
	CLR  R26
	CLR  R27
	CLR  R24
__ADDF123:
	CPI  R21,8
	BRLO __ADDF124
	MOV  R26,R27
	MOV  R27,R24
	CLR  R24
	SUBI R21,8
	RJMP __ADDF123
__ADDF124:
	TST  R21
	BREQ __ADDF126
__ADDF125:
	LSR  R24
	ROR  R27
	ROR  R26
	DEC  R21
	BRNE __ADDF125
__ADDF126:
	MOV  R21,R0
	EOR  R21,R1
	BRMI __ADDF127
	RCALL __UADD12
	BRCC __ADDF129
	ROR  R22
	ROR  R31
	ROR  R30
	INC  R23
	BRVC __ADDF129
	RJMP __MAXRES
__ADDF128:
	RCALL __SWAPACC
__ADDF129:
	RCALL __REPACK
	POP  R21
	RET
__ADDF1211:
	BRCC __ADDF128
	RJMP __ADDF129
__ADDF127:
	SUB  R30,R26
	SBC  R31,R27
	SBC  R22,R24
	BREQ __ZERORES
	BRCC __ADDF1210
	COM  R0
	RCALL __NEGMAN1
__ADDF1210:
	TST  R22
	BRMI __ADDF129
	LSL  R30
	ROL  R31
	ROL  R22
	DEC  R23
	BRVC __ADDF1210

__ZERORES:
	CLR  R30
	CLR  R31
	CLR  R22
	CLR  R23
	POP  R21
	RET

__MINRES:
	SER  R30
	SER  R31
	LDI  R22,0x7F
	SER  R23
	POP  R21
	RET

__MAXRES:
	SER  R30
	SER  R31
	LDI  R22,0x7F
	LDI  R23,0x7F
	POP  R21
	RET

__MULF12:
	PUSH R21
	RCALL __UNPACK
	CPI  R23,0x80
	BREQ __ZERORES
	CPI  R25,0x80
	BREQ __ZERORES
	EOR  R0,R1
	SEC
	ADC  R23,R25
	BRVC __MULF124
	BRLT __ZERORES
__MULF125:
	TST  R0
	BRMI __MINRES
	RJMP __MAXRES
__MULF124:
	PUSH R0
	PUSH R17
	PUSH R18
	PUSH R19
	PUSH R20
	CLR  R17
	CLR  R18
	CLR  R25
	MUL  R22,R24
	MOVW R20,R0
	MUL  R24,R31
	MOV  R19,R0
	ADD  R20,R1
	ADC  R21,R25
	MUL  R22,R27
	ADD  R19,R0
	ADC  R20,R1
	ADC  R21,R25
	MUL  R24,R30
	RCALL __MULF126
	MUL  R27,R31
	RCALL __MULF126
	MUL  R22,R26
	RCALL __MULF126
	MUL  R27,R30
	RCALL __MULF127
	MUL  R26,R31
	RCALL __MULF127
	MUL  R26,R30
	ADD  R17,R1
	ADC  R18,R25
	ADC  R19,R25
	ADC  R20,R25
	ADC  R21,R25
	MOV  R30,R19
	MOV  R31,R20
	MOV  R22,R21
	MOV  R21,R18
	POP  R20
	POP  R19
	POP  R18
	POP  R17
	POP  R0
	TST  R22
	BRMI __MULF122
	LSL  R21
	ROL  R30
	ROL  R31
	ROL  R22
	RJMP __MULF123
__MULF122:
	INC  R23
	BRVS __MULF125
__MULF123:
	RCALL __ROUND_REPACK
	POP  R21
	RET

__MULF127:
	ADD  R17,R0
	ADC  R18,R1
	ADC  R19,R25
	RJMP __MULF128
__MULF126:
	ADD  R18,R0
	ADC  R19,R1
__MULF128:
	ADC  R20,R25
	ADC  R21,R25
	RET

__DIVF21:
	PUSH R21
	RCALL __UNPACK
	CPI  R23,0x80
	BRNE __DIVF210
	TST  R1
__DIVF211:
	BRPL __DIVF219
	RJMP __MINRES
__DIVF219:
	RJMP __MAXRES
__DIVF210:
	CPI  R25,0x80
	BRNE __DIVF218
__DIVF217:
	RJMP __ZERORES
__DIVF218:
	EOR  R0,R1
	SEC
	SBC  R25,R23
	BRVC __DIVF216
	BRLT __DIVF217
	TST  R0
	RJMP __DIVF211
__DIVF216:
	MOV  R23,R25
	PUSH R17
	PUSH R18
	PUSH R19
	PUSH R20
	CLR  R1
	CLR  R17
	CLR  R18
	CLR  R19
	CLR  R20
	CLR  R21
	LDI  R25,32
__DIVF212:
	CP   R26,R30
	CPC  R27,R31
	CPC  R24,R22
	CPC  R20,R17
	BRLO __DIVF213
	SUB  R26,R30
	SBC  R27,R31
	SBC  R24,R22
	SBC  R20,R17
	SEC
	RJMP __DIVF214
__DIVF213:
	CLC
__DIVF214:
	ROL  R21
	ROL  R18
	ROL  R19
	ROL  R1
	ROL  R26
	ROL  R27
	ROL  R24
	ROL  R20
	DEC  R25
	BRNE __DIVF212
	MOVW R30,R18
	MOV  R22,R1
	POP  R20
	POP  R19
	POP  R18
	POP  R17
	TST  R22
	BRMI __DIVF215
	LSL  R21
	ROL  R30
	ROL  R31
	ROL  R22
	DEC  R23
	BRVS __DIVF217
__DIVF215:
	RCALL __ROUND_REPACK
	POP  R21
	RET

__ANEGD1:
	COM  R31
	COM  R22
	COM  R23
	NEG  R30
	SBCI R31,-1
	SBCI R22,-1
	SBCI R23,-1
	RET

__CWD1:
	MOV  R22,R31
	ADD  R22,R22
	SBC  R22,R22
	MOV  R23,R22
	RET

__DIVW21U:
	CLR  R0
	CLR  R1
	LDI  R25,16
__DIVW21U1:
	LSL  R26
	ROL  R27
	ROL  R0
	ROL  R1
	SUB  R0,R30
	SBC  R1,R31
	BRCC __DIVW21U2
	ADD  R0,R30
	ADC  R1,R31
	RJMP __DIVW21U3
__DIVW21U2:
	SBR  R26,1
__DIVW21U3:
	DEC  R25
	BRNE __DIVW21U1
	MOVW R30,R26
	MOVW R26,R0
	RET

__SWAPD12:
	MOV  R1,R24
	MOV  R24,R22
	MOV  R22,R1
	MOV  R1,R25
	MOV  R25,R23
	MOV  R23,R1

__SWAPW12:
	MOV  R1,R27
	MOV  R27,R31
	MOV  R31,R1

__SWAPB12:
	MOV  R1,R26
	MOV  R26,R30
	MOV  R30,R1
	RET

__SAVELOCR2:
	ST   -Y,R17
	ST   -Y,R16
	RET

__LOADLOCR2:
	LDD  R17,Y+1
	LD   R16,Y
	RET

;END OF CODE MARKER
__END_OF_CODE:
