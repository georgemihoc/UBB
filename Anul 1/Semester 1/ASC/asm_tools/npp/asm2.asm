bits 32 

global start        

extern exit
extern scanf
extern printf
       
import exit msvcrt.dll 
import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll

segment data use32 class=data
    afisare db "nr*2= %d",0 
    citire db "&d",0
    mesajcitire db "Introduceti n= ",0
    n db 0
  
segment code use32 class=code
    start:
    ;printare mesaj
    push dword mesajcitire
    call [printf]
    add esp, 4*1
    mov al, 2
    imul byte[n];ax
    cwde
    push eax
    push dword afisare
    call [printf]
    add esp,4*2
    
    
    push dword n
    push dword citire
    call [scanf]
    
   
    push    dword 0     
    call    [exit]       