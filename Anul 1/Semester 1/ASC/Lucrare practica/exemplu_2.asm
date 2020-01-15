; Codul de mai jos va deschide un fisier numit "ana.txt" din directorul curent, va citi un text scurt din acel fisier, apoi va afisa  in consola numarul de caractere citite si textul citit din fisier.
; Programul va folosi functia fopen pentru deschiderea fisierului, functia fread pentru citirea din fisier si functia fclose pentru inchiderea fisierului creat.
; Deoarece in apelul functiei fopen programul foloseste modul de acces "r", daca un fisier numele dat nu exista in directorul curent,  apelul functiei fopen nu va reusi (eroare). Detalii despre modurile de acces sunt prezentate in sectiunea "Suport teoretic".

; In acest program sirul de caractere in care se va citi textul din fisier trebuie sa aiba o lungime cu 1 mai mare decat numarul maxim  de elemente care vor fi citite din fisier deoarece acest sir va fi afisat in consola folosind functia printf.
; Orice sir de caractere folosit de functia printf trebuie sa fie terminat in 0, altfel afisarea nu va fi corecta.
; Daca fisierul ar contine mai mult de <len> caractere si dimensiunea sirului destinatie era exact <len>, intregul sir ar fi fost completat cu valori citite din fisier, astfel sirul nu se mai termina cu valoarea 0.

bits 32 

global start        

; declare external functions needed by our program
extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll  
import fopen msvcrt.dll  
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "date.txt", 0  
    mod_acces db "r", 0        
    spatiu db ' '                       
    len equ 100                                          
    text times (len+1) db 0
    lens equ $-text
    descriptor_fis dd -1    
    format db "Am citit %d caractere din fisier. Textul este: %s", 0  

segment code use32 class=code
    start:
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2            

        mov [descriptor_fis], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
        
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0
        je final
        
        ; eax = fread(text, 1, len, descriptor_fis)
        push dword [descriptor_fis]
        push dword len
        push dword 1
        push dword text        
        call [fread]
        add esp, 4*4                
        
        
        mov esi, 0
        mov ecx, eax
        mov bl, [spatiu]
        repeta:
            mov dl, [text+esi]
            cmp dl, bl
            je departe
            times 2 dec dl
            mov [text+esi], dl
            departe:
                inc esi
                jecxz fi
                loop repeta
        fi:
        ; printf(format, eax, text)
        push dword text
        push dword EAX
        push dword format
        call [printf]
        add esp, 4*3
        
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
        
        final:
        push    dword 0      
        call    [exit]       