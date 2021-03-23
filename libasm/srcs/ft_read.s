# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-sant <gde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 16:41:22 by gde-sant          #+#    #+#              #
#    Updated: 2020/12/08 16:41:22 by gde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_read
extern	__errno_location

ft_read: 
    mov     rax, 0
    syscall
    cmp     rax, 0
    jl      error
    ret 

error:
	neg     rax
	push    rax
    call    __errno_location wrt ..plt
    pop     qword [rax]          
    mov     rax, -1
    ret