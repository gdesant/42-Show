# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-sant <gde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 16:41:22 by gde-sant          #+#    #+#              #
#    Updated: 2020/12/08 16:41:22 by gde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcpy

ft_strcpy: 
            mov     rax, 0        ; i = 0
            jmp     loop           ; execute loop  

loop:
            mov		cl, [rsi + rax]      ; buff = source[rsi]
            mov		[rdi + rax], cl      ; dest[rdi] = buff
            cmp     cl, 0       ; compare str[rdi + rax] et '/0'
            jne     next           ; si != 0 recommence loop
            mov     rax, rdi
            ret


next:
            inc     rax            ;rax++
            jmp     loop           ;execute loop
