# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-sant <gde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 16:41:22 by gde-sant          #+#    #+#              #
#    Updated: 2020/12/08 16:41:22 by gde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


extern ft_strlen
extern malloc
extern ft_strcpy
global ft_strdup


ft_strdup: 
            push    rdi          ; buff12 = rdi
            call    ft_strlen         ; rax = ft_strlen(rdi)
            inc     rax               ; rdi++
            mov     rdi, rax          ; rdi = rax
            call    malloc wrt ..plt            ; rax = malloc(rdi)
            cmp     rax, 0            ; check erreur malloc
            je      quit              ; si erreur, errno definie par malloc donc quit
            pop     rsi
            mov     rdi, rax          ; rdi = rax
            call    ft_strcpy        ; rax = strlcpy(rdi, rsi)
	        ret

quit:
            pop rdi
            ret
