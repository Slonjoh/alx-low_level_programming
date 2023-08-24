section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0
    newline db 10, 0

section .text
    global main

main:
    push rax
    push rbx
    push rcx
    push rdx

    ; Print "Hello, Holberton"
    mov rdi, format
    mov rsi, hello
    call printf

    ; Print newline
    mov rdi, format
    mov rsi, newline
    call printf

    pop rdx
    pop rcx
    pop rbx
    pop rax

    ret

section .bss
    resb 1 ; Reserve space for the null-terminator

section .extern
    extern printf

