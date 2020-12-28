section .text
    global _ft_strlen
_ft_strlen:
            mov rax, 0
strlenloop:
            cmp BYTE [rdi + rax], 0
            je return
            inc rax
            jne strlenloop
return:
            ret