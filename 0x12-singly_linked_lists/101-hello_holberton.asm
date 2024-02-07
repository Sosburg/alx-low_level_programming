section .data
hello db 'Hello, Holberton', 0

section .text
global main

main:
; Prepare arguments for printf
mov rdi, hello
mov rax, 0
call printf

; Exit the program
mov rax, 60         ; syscall: exit
xor rdi, rdi        ; status: 0
syscall

section .bss
; Dummy printf function for linking
extern printf

