push_ax
push_bx
push_cx
call 0$
out
halt

0:
push 0
push_deep 3
push_deep 4
mul
push 4
push_deep 6
mul
push_deep 4
mul
sub
pop_deep 1
push_deep 1
push 0
jbe 1$
push 0
push_deep 4
sub
push_deep 2
sqrt
add
push 2
push_deep 6
mul
div
out
push 0
push_deep 4
sub
push_deep 2
sqrt
sub
push 2
push_deep 6
mul
div
out
push 2
drop 4
ret
1:
push_deep 1
push 0
jne 2$
push 0
push_deep 4
sub
push 2
push_deep 6
mul
div
out
push 1
drop 4
ret
2:
push_deep 1
push 0
jae 3$
push 0
drop 4
ret
3:
