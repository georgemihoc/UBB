bits 32

global start        

extern exit               
extern printf
extern scanf
;extern Afisare
import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll    

segment data use32 class=data
    ; ...
    ;formatcitire db "%d",0
    ;formatafisare db "A si B:",0
    ;formatafisare db "%d ",0
    ;formatafisare2 db "A si D: ",0
    ;formatafisare3 db "B si D: %d ",0
    ;formatafisare db "A si B:%d, %d, %d, %d ",0
    formatafisare db "%d ",0
    a db 1,2,3,4
    len equ ($-a)
    b resd 10
    lenb dd 0
    doi dw 2
   
segment code use32 class=code
    start:
        mov ecx, len
        
        mov edx, [lenb]
        mov ebx, 0 
        mov eax, 0
        mov edi, 0
        mov esi, 0
        repeta:
            mov bl, byte[a+esi]
            ;movzx ebx, bl
            inc esi  
            movzx bx, bl
            mov ax, bx
            
            ;mov edx, ecx
            ;mov ecx, [a+esi]
            ;prim:
                
            ;mov dl, [doi]
            ;div dl
            ;cmp ah,0
            ;je mai
            movzx ebx, bx
            ;jl mai
            mov [b+edi],ebx
            ;mov edx,[lenb]
            inc edx 
            inc edi
            mai:
        jecxz sari
        loop repeta
        sari:
        mov esi,0
        mov ecx, edx
        afis:
            
            mov al,[b+esi]
            movzx eax, al
            inc esi
            pushad
            push eax
            push formatafisare
            call [printf]
            add esp,4*2
            popad
            jecxz final
        loop afis

        final:
        ;add esp,4*2    
        push    dword 0      
        call    [exit]       
        