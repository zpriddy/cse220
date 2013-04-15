;***************************************************************************************************
; FILE: sum.s
;***************************************************************************************************

;---------------------------------------------------------------------------------------------------
; Defines a data segment. The data segment is located at memory address 51210 = 00200h.
;---------------------------------------------------------------------------------------------------

.DATA 512
$sum        0                   ; Stores the sum
$i          0                   ; Loop index variable
$n          3                   ; Sum of the first n = 3 positive integers.

;---------------------------------------------------------------------------------------------------
; Defines a text (code) segment. The text segment is located at memory address 102410 = 00400h.
;---------------------------------------------------------------------------------------------------

.TEXT 1024
            LDI    %A 0         ; %A <- 0
            ST     $sum %A	; $sum <- 0
@loop       LDI    %B 1         ; $A <- $A + 1
            ADD    %A
            ST     $i %A        ; $i <- %A
            LD     %B $n        ; %B <- n
            BLT    @loop1       ; If $i < $n keep looping
            BEQ    @loop1       ; If $i = $n keep looping
            BR     @endloop     ; i > $n so drop out of loop
@loop1      LD     %B $sum      ; %B <- $sum
            LD     %A $i        ; %A <- $i
            ADD    %B           ; %B <- $sum + i
            ST     $sum %B      ; $sum <- $sum + i
            BR     @loop        ; Continue looping as long as $i = $n
@endloop    HALT
