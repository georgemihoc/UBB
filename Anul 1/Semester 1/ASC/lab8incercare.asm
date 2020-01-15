bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit
extern printf
extern scanf
extern fopen,fread,fwrite,fclose
import fopen msvcrt.dll
import fread msvcrt.dll
import fwrite msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    mesaj_1 db "dati numele fisierului: ",0
    mesaj_2 db " dati cheia de criptare: ",0
    format_s db '%s',0
    mod_f db 'r+',0
    nume_f resb 20
    buffer_r resb 6
    cheie resb 2
    nr_c dd 0
    handle_f dd -1
    
    
; our code starts here
segment code use32 class=code
    start:
        ;citim numele fisierului de la tastatura
        push mesaj_1
        push format_s
        call [printf]
        add esp,4*2
        
        push nume_f
        push format_s
        call [scanf]
        add esp,4*2
        
        ;citim "cheia" de "criptare"
        push mesaj_2
        push format_s
        call [printf]
        add esp,4*2
        
        push cheie
        push format_s
        call [scanf]
        add esp,4*2
        
        ;deschid fisierul
        push mod_f
        push nume_f
        call [fopen]
        add esp,4*2
        
        cmp eax,0
        je final
        mov [handle_f],eax
        
        ;citesc continutul fisierului
        repeta_cititre:
            push dword [handle_f]   ; adresa file handle
            push dword 6            ; nr elemente ce vreau sa le citesc
            push dword 1            ; dimensiunea in octeti a unui element
            push buffer_r
            call [fread]
            add esp,4*4
            ;eax <- nr elemente citite din fisier
            mov [nr_c],eax
            
            ;prelucrare buffer
            cld
            mov ecx,[nr_c]
            mov esi,buffer_r
            mov edi,esi
            repeta:
                lodsb    ; al<- <ds:esi> , ins esi
                xor al,[cheie]
                stosb    ; <es:edi> <- al , inc edi
                loop repeta
            
            
            ;verificare daca am citit tot fisierul
            cmp dword [nr_c],6
            je repeta_cititre
            
        ;inchid fisierul
        push handle_f
        call [fclose]
        
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
