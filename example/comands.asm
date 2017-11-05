push 5
push 10
add
push 3
mul
push 13
sub
jmp 1:
push 8
div
1:
call 2:
out
halt
2:
push 8
div
ret

