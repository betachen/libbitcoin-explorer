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
#ifndef BX_URI_ENCODE_HPP
#define BX_URI_ENCODE_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/explorer/command.hpp>
#include <bitcoin/explorer/define.hpp>
#include <bitcoin/explorer/generated.hpp>
#include <bitcoin/explorer/primitives/address.hpp>
#include <bitcoin/explorer/primitives/base16.hpp>
#include <bitcoin/explorer/primitives/base2.hpp>
#include <bitcoin/explorer/primitives/base58.hpp>
#include <bitcoin/explorer/primitives/base64.hpp>
#include <bitcoin/explorer/primitives/base85.hpp>
#include <bitcoin/explorer/primitives/btc.hpp>
#include <bitcoin/explorer/primitives/btc160.hpp>
#include <bitcoin/explorer/primitives/btc256.hpp>
#include <bitcoin/explorer/primitives/byte.hpp>
#include <bitcoin/explorer/primitives/certificate.hpp>
#include <bitcoin/explorer/primitives/ec_private.hpp>
#include <bitcoin/explorer/primitives/ec_public.hpp>
#include <bitcoin/explorer/primitives/encoding.hpp>
#include <bitcoin/explorer/primitives/endorsement.hpp>
#include <bitcoin/explorer/primitives/hashtype.hpp>
#include <bitcoin/explorer/primitives/hd_key.hpp>
#include <bitcoin/explorer/primitives/hd_priv.hpp>
#include <bitcoin/explorer/primitives/hd_pub.hpp>
#include <bitcoin/explorer/primitives/header.hpp>
#include <bitcoin/explorer/primitives/input.hpp>
#include <bitcoin/explorer/primitives/output.hpp>
#include <bitcoin/explorer/primitives/raw.hpp>
#include <bitcoin/explorer/primitives/script.hpp>
#include <bitcoin/explorer/primitives/signature.hpp>
#include <bitcoin/explorer/primitives/stealth.hpp>
#include <bitcoin/explorer/primitives/transaction.hpp>
#include <bitcoin/explorer/primitives/uri.hpp>
#include <bitcoin/explorer/primitives/wif.hpp>
#include <bitcoin/explorer/primitives/wrapper.hpp>
#include <bitcoin/explorer/utility.hpp>

/********* GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY **********/

namespace libbitcoin {
namespace explorer {
namespace commands {

/**
 * Various localizable strings.
 */
#define BX_URI_ENCODE_ADDRESS_CONFLICT \
    "Only one Bitcoin or stealth address may specified."

/**
 * Class to implement the uri-encode command.
 */
class uri_encode 
    : public command
{
public:

    /**
     * The symbolic (not localizable) command name, lower case.
     */
    BCX_API static const char* symbol()
    {
        return "uri-encode";
    }


    /**
     * The member symbolic (not localizable) command name, lower case.
     */
    BCX_API virtual const char* name()
    {
        return uri_encode::symbol();
    }

    /**
     * The localizable command category name, upper case.
     */
    BCX_API virtual const char* category()
    {
        return "WALLET";
    }

    /**
     * The localizable command description.
     */
    BCX_API virtual const char* description()
    {
        return "Compose a Bitcoin URI from specified parts.";
    }

    /**
     * Load program argument definitions.
     * A value of -1 indicates that the number of instances is unlimited.
     * @return  The loaded program argument definitions.
     */
    BCX_API virtual arguments_metadata& load_arguments()
    {
        return get_argument_metadata()
            .add("BITCOIN_ADDRESS", 1);
    }

	/**
     * Load parameter fallbacks from file or input as appropriate.
     * @param[in]  input  The input stream for loading the parameters.
     * @param[in]         The loaded variables.
     */
    BCX_API virtual void load_fallbacks(std::istream& input, 
        po::variables_map& variables)
    {
    }

    /**
     * Load program option definitions.
     * BUGBUG: see boost bug/fix: svn.boost.org/trac/boost/ticket/8009
     * @return  The loaded program option definitions.
     */
    BCX_API virtual options_metadata& load_options()
    {
        using namespace po;
        options_description& options = get_option_metadata();
        options.add_options()
        (
            BX_HELP_VARIABLE ",h",
            value<bool>()->zero_tokens(),
            "Get a description and instructions for this command."
        )
        (
            BX_CONFIG_VARIABLE ",c",
            value<boost::filesystem::path>(),
            "The path to the configuration settings file."
        )
        (
            "amount,a",
            value<primitives::btc>(&option_.amount),
            "The value of the amount parameter."
        )
        (
            "label,l",
            value<std::string>(&option_.label),
            "The value of the label parameter."
        )
        (
            "message,m",
            value<std::string>(&option_.message),
            "The value of the label parameter."
        )
        (
            "request,r",
            value<primitives::uri>(&option_.request),
            "The value of the payment request parameter."
        )
        (
            "stealth,s",
            value<primitives::stealth>(&option_.stealth),
            "The stealth address for the address part."
        )
        (
            "BITCOIN_ADDRESS",
            value<primitives::address>(&argument_.bitcoin_address),
            "The Bitcoin address for the address part."
        );

        return options;
    }

    /**
     * Invoke the command.
     * @param[out]  output  The input stream for the command execution.
     * @param[out]  error   The input stream for the command execution.
     * @return              The appropriate console return code { -1, 0, 1 }.
     */
    BCX_API virtual console_result invoke(std::ostream& output,
        std::ostream& cerr);

    /* Properties */

    /**
     * Get the value of the BITCOIN_ADDRESS argument.
     */
    BCX_API virtual primitives::address& get_bitcoin_address_argument()
    {
        return argument_.bitcoin_address;
    }

    /**
     * Set the value of the BITCOIN_ADDRESS argument.
     */
    BCX_API virtual void set_bitcoin_address_argument(
        const primitives::address& value)
    {
        argument_.bitcoin_address = value;
    }

    /**
     * Get the value of the amount option.
     */
    BCX_API virtual primitives::btc& get_amount_option()
    {
        return option_.amount;
    }

    /**
     * Set the value of the amount option.
     */
    BCX_API virtual void set_amount_option(
        const primitives::btc& value)
    {
        option_.amount = value;
    }

    /**
     * Get the value of the label option.
     */
    BCX_API virtual std::string& get_label_option()
    {
        return option_.label;
    }

    /**
     * Set the value of the label option.
     */
    BCX_API virtual void set_label_option(
        const std::string& value)
    {
        option_.label = value;
    }

    /**
     * Get the value of the message option.
     */
    BCX_API virtual std::string& get_message_option()
    {
        return option_.message;
    }

    /**
     * Set the value of the message option.
     */
    BCX_API virtual void set_message_option(
        const std::string& value)
    {
        option_.message = value;
    }

    /**
     * Get the value of the request option.
     */
    BCX_API virtual primitives::uri& get_request_option()
    {
        return option_.request;
    }

    /**
     * Set the value of the request option.
     */
    BCX_API virtual void set_request_option(
        const primitives::uri& value)
    {
        option_.request = value;
    }

    /**
     * Get the value of the stealth option.
     */
    BCX_API virtual primitives::stealth& get_stealth_option()
    {
        return option_.stealth;
    }

    /**
     * Set the value of the stealth option.
     */
    BCX_API virtual void set_stealth_option(
        const primitives::stealth& value)
    {
        option_.stealth = value;
    }

private:

    /**
     * Command line argument bound variables.
     * Uses cross-compiler safe constructor-based zeroize.
     * Zeroize for unit test consistency with program_options initialization.
     */
    struct argument
    {
        argument()
          : bitcoin_address()
        {
        }

        primitives::address bitcoin_address;
    } argument_;

    /**
     * Command line option bound variables.
     * Uses cross-compiler safe constructor-based zeroize.
     * Zeroize for unit test consistency with program_options initialization.
     */
    struct option
    {
        option()
          : amount(),
            label(),
            message(),
            request(),
            stealth()
        {
        }

        primitives::btc amount;
        std::string label;
        std::string message;
        primitives::uri request;
        primitives::stealth stealth;
    } option_;
};

} // namespace commands
} // namespace explorer
} // namespace libbitcoin

#endif
