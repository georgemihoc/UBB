bits 32 
global start        
extern exit  
extern printf 
import printf msvcrt.dll    
import exit msvcrt.dll   

segment data use32 class=data

    a dw 0ABABh, 0FEDCh, 0ABBCh
    
    mesajrez db "Rezultat: %d",10,13

    ;Lab 2 ASC EX 4 Inmultiri si impartiri a b c  d byte e f word
    ;[[b*c-(e+f)]/(a+d) = 20 - 5 )/ 5 = 3

segment code use32 class=code

    start:
        mov ax, 0ffffh 
        cwd 
        add dx, 1 
        mov bx, 65535 
        div bx
        
        push dword mesajrez
        call [printf]
        
        add esp, 16
        push    dword 0
        call    [exit]  