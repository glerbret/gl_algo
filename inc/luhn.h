/**
 * @brief Calcul et de controle des <a href="https://fr.wikipedia.org/wiki/Formule_de_Luhn">cles de Luhn</a>
 * @copyright MIT license
 * @author Gregory Lerbret
 */
#ifndef LUHN_H
#define LUHN_H

#include <string_view>

namespace gl::luhn
{
/**
 * @brief Calcul de la cle de Luhn
 *
 * @param[in] number  Numero sur lequel calculer la cle
 *
 * @return Cle de Luhn
 */
int calculate_key(std::string_view number);

/**
 * @brief Verification de la cle de Luhn
 *
 * @param[in] number  Numero a verifier
 *
 * @retval true   Cle de Luhn valide
 * @retval false  Cle de Luhn invalide
 */
bool check_key(std::string_view number);
}

#endif
