/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2011 Danny van Dyk
 *
 * This file is part of the EOS project. EOS is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * EOS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <eos/utils/verify.hh>

namespace eos
{
    VerifiedRangeError::VerifiedRangeError(const std::string & message) :
        Exception("VerifiedRange encountered bogus value: " + message)
    {
    }

    VerifiedRangeOverflow::VerifiedRangeOverflow(const std::string & value, const std::string & maximum) :
        VerifiedRangeError("'" + value + "' larger than maximum of '" + maximum + "'")
    {
    }

    VerifiedRangeUnderflow::VerifiedRangeUnderflow(const std::string & value, const std::string & maximum) :
        VerifiedRangeError("'" + value + "' smaller than minimum of '" + maximum + "'")
    {
    }
} // namespace eos
