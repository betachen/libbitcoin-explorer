/**
 * Copyright (c) 2011-2014 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HD_PUBLIC_HPP
#define HD_PUBLIC_HPP

#include <iostream>
#include <string>
#include <bitcoin/explorer/define.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace libbitcoin {
namespace explorer {
namespace primitives {

/**
 * Serialization helper to convert between base16 string and hd_public_key.
 */
class hd_pub
{
public:

    /**
     * Default constructor.
     */
    BCX_API hd_pub();

    /**
     * Initialization constructor.
     * @param[in]  base58  The value to initialize with.
     */
    BCX_API hd_pub(const std::string& base58);

    /**
     * Initialization constructor.
     * @param[in]  value  The value to initialize with.
     */
    BCX_API hd_pub(const hd_public_key& value);

    /**
     * Copy constructor.
     * @param[in]  other  The object to copy into self on construct.
     */
    BCX_API hd_pub(const hd_pub& other);

    /**
     * Return a reference to the data member.
     * @return  A reference to the object's internal data.
     */
    BCX_API hd_public_key& data();

    /**
     * Overload cast to internal type.
     * @return  This object's value cast to internal type.
     */
    BCX_API operator const hd_public_key&() const;

    /**
     * Overload stream in. Throws if input is invalid.
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    BCX_API friend std::istream& operator>>(std::istream& input,
        hd_pub& argument);

    /**
     * Overload stream out.
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    BCX_API friend std::ostream& operator<<(std::ostream& output,
        const hd_pub& argument);

private:

    /**
     * The state of this object.
     */
    hd_public_key value_;
};

} // namespace explorer
} // namespace primitives
} // namespace libbitcoin

#endif