in
in
in
push_cx
push_bx
push_ax 
pop_bx
pop_bx
mul
pop_ax
pop_cx
push 4
mul
mul
sub
sqrt
push_dx
push 0
pop_dx
ja 9$
push 0
pop_dx
je 8$
push 0
pop_dx
jb 7$
end
7:
pop_ax
push 2
mul
pop_dx
pop_bx
push -1
mul
add
div
out
pop_ax
push 2
mul
pop_dx
pop_bx
push -1
mul
sub
div
out
8:
pop_ax
push 2
mul
pop_bx
div
push -1
mul
out
9:
end
