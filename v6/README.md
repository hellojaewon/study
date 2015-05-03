# UNIX V6

UNIX V6 was the first version of the Unix operating System. It was released in May 1975 and targeted DEC PDP-11 family of minicomputers.

# PDP-11/40

The PDP-11 is a series of 16-bit minicomputers sold by Digital Equipment Corporation (DEC) from 1970 into the 1990s.

## General Purpose Registers

- r0, r1
 - for computation, return value of function
- r2, r3, r4
 - local use
- r5
 - frame pointer, environment pointer
- r6
 - stack pointer
- r7
 - program counter

## Instruction Set Architecture

- MOV
 - mov s d
 - copy from source(s) to destination(d)
 - MOV XXX, R1 loads register 1 with the content of memory location XXX.
 - MOV #20, R0 loads the number 20 into register 0. '#' indicates that the value 20 is the operand.

- RTS
 - rts reg
 - loads the content of the reg into PC and pops the top element of the processor stack into the specified register.

- TRAP
 - sys command and its arguments are encoded as trap instruction.

## Memory

PDP-11/40 use 18 bits for memory addressing. Therefore, it has 256KB memory.

The upper 8KB is mapped to registers for peripheral.

The virtual address has 16 bits address so each process can use up to 64KB.

The virtual address is converted to physical address by memory management unit(MMU).

MMU uses active page register(APR) that is composed of page address register(PAR) and page description register(PDR) for address translation.

# References
- <a href="http://en.wikipedia.org/wiki/Version_6_Unix">UNIX V6</a>

- <a href="http://en.wikipedia.org/wiki/PDP-11">PDP-11</a>

- <a href="http://minnie.tuhs.org/Archive/PDP-11/Distributions/research/Dennis_v6/">UNIX V6 Source Code</a>

- <a href="http://pdos.csail.mit.edu/6.828/2005/readings/pdp11-40.pdf">PDP-11/40 Processor Handbook</a>
