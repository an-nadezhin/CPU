in
in
in
pop_cx
pop_bx
pop_ax
push_bx
push_bx
mul
push_ax
push_cx
push 4
mul
mul
sub
pop_dx
push 0
push_dx
ja 9$
push 0
push_dx
je 8$
push 0
push_dx
jb 7$
halt
7:
push 2
out
push_bx
push -1
mul
push_dx
sqrt
add
push_ax
push 2
mul
div
out
push_bx
push -1
mul
push_dx
sqrt
sub
push_ax
push 2
mul
div
out
halt
8:
push_ax
push 0
je 6$
push 1
out
push_ax
push 2
mul
push_bx
div
push -1
mul
out
halt
9:
push 0
out
no_roots
halt
6:
push 0
out
inf
halt
