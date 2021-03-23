# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-sant <gde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 16:41:22 by gde-sant          #+#    #+#              #
#    Updated: 2020/12/08 16:41:22 by gde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strlen

ft_strlen: 
            mov     rax, 0              ; i = 0
            jmp     loop                ; execute loop  

loop:
            cmp     BYTE [rdi + rax], 0 ; compare str[rdi + rax] et '/0'
            je      quit                ; si == quitte
            inc     rax                 ; rax++
            jmp     loop                ; recommence loop

quit :
            ret