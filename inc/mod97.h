/**
 * @brief Calcul et de controle des modulos 97 (clés RIB, NIR et RMLC)
 * @copyright MIT license
 * @author Gregory Lerbret
 */
#ifndef MOD97_H
#define MOD97_H

#include <string_view>

namespace gl::mod97
{
/**
 * @brief Calcul de la cle d'un RIB
 *
 * @param[in] number  Numero sur lequel calculer la cle
 *
 * @return Cle du RIB
 */
int calculate_rib_key(std::string_view number);

/**
 * @brief Verification de la cle d'un RIB
 *
 * @param[in] number  Numero a verifier
 *
 * @retval true   Cle valide
 * @retval false  Cle invalide
 */
bool check_rib_key(std::string_view number);

/**
 * @brief Calcul d'une cle NIR (securite sociale)
 *
 * @param[in] number  Numero sur lequel calculer la cle
 *
 * @return Cle NIR
 */
int calculate_nir_key(std::string_view number);

/**
 * @brief Verification d'une cle NIR (securite sociale)
 *
 * @param[in] number  Numero a verifier
 * @param[in] key     Cle a verifier
 *
 * @retval true   Cle valide
 * @retval false  Cle invalide
 */
bool check_nir_key(std::string_view number, int key);

/**
 * @brief Calcul de la cle RMLC d'un cheque
 *
 * @param[in] number  Numero sur lequel calculer la cle
 *
 * @return Cle RMLC
 */
int calculate_rmlc_key(std::string_view number);

/**
 * @brief Verification de la cle RMLC d'un cheque
 *
 * @param[in] number  Numero a verifier
 *
 * @retval true   Cle valide
 * @retval false  Cle invalide
 */
bool check_rmlc_key(std::string_view number);
}

#endif
