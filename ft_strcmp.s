section .text
    global _ft_strcmp
_ft_strcmp:
            mov rcx, -1
            mov rdx, 0
            mov rbx, 0
Loop:
            inc rcx
            mov dl, BYTE [rdi + rcx]
            mov bl, BYTE [rsi + rcx]
            cmp rdx, 0
            je return
            cmp rbx, 0
            je return
            sub rdx, rbx
            mov rax, rdx
            cmp rax, 0
            je  Loop
            ret
return:
            sub rdx, rbx
            mov rax, rdx
            ret