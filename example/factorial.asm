push 7
call 1$
out
halt
1:
pop_ax
push_ax
push_ax
push 1
jbe 2$
push_ax
push 1
sub
call 1$
mul
ret
2:
pop_cx
push 1
ret

