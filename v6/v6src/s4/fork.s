/ C library -- fork

/ pid = fork();
/
/ pid == 0 in child process; pid == -1 means error return
/ in child, parents id is in par_uid if needed

.globl	_fork, cerror, _par_uid

_fork:
    / saves the current environment into the stack.
	mov	r5,-(sp)
    / TODO: what does it mean?
	mov	sp,r5
    / sys is converted to trap instaruction.
    / assembler encodes sys and its first parameter as trap.
	sys	fork
        / unconditional branch.
        / the fork system call adjusts program counter in case of
        / not child process. Therefore, only child process executes
        / unconditional branch instruction.
		br 1f
    / bec checks PSW[0](process status word).
    / PSW[0] is set when system call fails.
	bec	2f
    / cerror is defined in v6srv/s4/cerror.s
    / it sets errno and return -1.
	jmp	cerror
1:
    / set _par_uid as parent's process id(r0) that was set in the sys fork
    / through u.u_ar0[R0] = p1->p_pid.
	mov	r0,_par_uid
    / clear r0.
    / child user process that called fork will receive 0 as return value.
	clr	r0
2:
    / restores the environment saved before calling fork
	mov	(sp)+,r5
    / TODO: what does it mean?
    / according to the book descriptions...
    / parent - rts instruction returns the control where called C library fork.
    / child - rts instruction calls C library fork, so it returns 0
    / stored in r0.
	rts	pc
.bss
/ TODO:
_par_uid: .=.+2
