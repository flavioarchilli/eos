/*
 * Copyright (c) 2021-2023 Danny van Dyk
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

#ifndef EOS_GUARD_EOS_UTILS_EXPRESSION_CACHER_HH
#define EOS_GUARD_EOS_UTILS_EXPRESSION_CACHER_HH 1

#include <eos/utils/expression-fwd.hh>
#include <eos/utils/observable_cache.hh>

namespace eos::exp
{
    // Visit the expression tree, cache all observables, and replace them with the cached observables
    class ExpressionCacher
    {
        private:
            ObservableCache _cache;

        public:
            ExpressionCacher(const ObservableCache & cache);
            ~ExpressionCacher() = default;

            Expression visit(const BinaryExpression & e);

            Expression visit(const FunctionExpression & e);

            Expression visit(const ConstantExpression & e);

            Expression visit(const ObservableNameExpression & e);

            Expression visit(const ObservableExpression & e);

            Expression visit(const ParameterNameExpression & e);

            Expression visit(const ParameterExpression & e);

            Expression visit(const KinematicVariableNameExpression & e);

            Expression visit(const KinematicVariableExpression & e);

            Expression visit(const CachedObservableExpression & e);
    };
} // namespace eos::exp

#endif
