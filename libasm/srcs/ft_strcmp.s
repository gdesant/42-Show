# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-sant <gde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 16:41:22 by gde-sant          #+#    #+#              #
#    Updated: 2020/12/08 16:41:22 by gde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
global ft_strcmp

ft_strcmp: 
	mov	rax, 0
    mov rcx, 0
	jmp	loop			; execute loop  

loop:
	mov	r8b, BYTE [rdi + rcx]
	mov	r9b, BYTE [rsi + rcx]
	cmp	r8b, 0
    je	endloop
    cmp r9b, 0
    je  endloop
    cmp r8b, r9b
    jne endloop  
    inc rcx
    jmp loop


endloop:
    movzx rax, r8b
    movzx rbx, r9b
    sub rax, rbx
	ret
