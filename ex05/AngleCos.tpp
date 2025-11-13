/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AngleCos.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:46:22 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/13 19:38:56 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Vector.hpp"

template<typename T>
T	custom_abs( T a )
{
	return a >= 0 ? a : -a;
}


/**
 * @brief Cosinus de l’angle entre deux vecteurs.
 * Calcule cos(θ) = ⟨u,v⟩ / (||u|| · ||v||).
 * @tparam K Type des composantes (réel/entier/complexe).
 * @param u Vecteur u (non vide).
 * @param v Vecteur v (même taille que u).
 * @return std::common_type_t<K,double> (réel dans [-1, 1]).
 * @throws std::runtime_error si tailles différentes ou norme nulle.
 * @complexity O(n).
 * @note Pour K complexe, le produit scalaire est hermitien (conjugaison).
 */
template<is_arithmetic K>
auto	angle_cos( const Vector<K>& u, const Vector<K>& v )
	-> std::common_type_t<K, double>
{
	using promoted_t = std::common_type_t<K, double>;
	const double	eps = 1e-12;

	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input vectors are empty");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for cos angle calculation");

	promoted_t	d = static_cast<promoted_t>(u.dot(v));
	double		nu = u.norm();
	double		nv = v.norm();

	if (custom_abs(nu) < eps || custom_abs(nv) < eps)
        throw std::runtime_error("Error: zero-length vector (cannot compute angle)");
	return (d / (nu * nv));
}
