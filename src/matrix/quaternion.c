/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:10:23 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/17 13:16:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/* Q49. How do I calculate the conjugate of a quaternion? */
/* ------------------------------------------------------ */

/*   This can be achieved by reversing the polarity (or negating) the */
/*     vector part of the quaternion, ie: */
/* 	    -- */
/* 		    Qr =  ( Qr.scalar, -Qr.vector ) */


void	quaternion_conjugate(t_vector4 *qr, t_vector4 const *qa)
{
	qr->w =  qa->w;
	qr->x = -qa->x;
	qr->y = -qa->y;
	qr->z = -qa->z;
}

/* Q51. How do I calculate the magnitude of a quaternion? */
/* ------------------------------------------------------ */

/* The magnitude of a quaternion is calculated by multiplying the */
/* quaternion with its conjugate ie: */

/* 				------------ */
/* 			  /      	  -- */
/* |Qr| =  \/     	   Qr.Qr */

/* This can be implemented as the following code sequence: */

/* ------------------------------------------------------------------- */

float quaternion_magnitude(t_vector4 *qa)
{
	return (sqrt(
				qa->w * qa->w
				+ qa->x * qa->x
				+ qa->y * qa->y
				+ qa->z * qa->z
				));
}
