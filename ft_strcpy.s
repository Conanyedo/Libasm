section .text
    global _ft_strcpy
_ft_strcpy:
            mov rax, 0
Loop:
            cmp BYTE [rsi + rax], 0
            je return
            mov dl, BYTE [rsi + rax]
            mov BYTE [rdi + rax], dl
            inc rax
            jmp Loop
return:
            mov BYTE [rdi + rax], 0
            mov rax, rdi
            ret
