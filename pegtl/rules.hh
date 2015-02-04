// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_RULES_HH
#define PEGTL_RULES_HH

#include "internal/rules.hh"

namespace pegtl
{
   struct parse_error;

   template< typename ... Rules > struct at : internal::at< Rules ... > {};
   template< typename ... Rules > struct at_try_catch : internal::at_try_catch_type< parse_error, Rules ... > {};
   template< typename Exception, typename ... Rules > struct at_try_catch_type : internal::at_try_catch_type< Exception, Rules ... > {};
   template< unsigned Num > struct bytes : internal::bytes< Num > {};
   template< template< typename ... > class Control, typename ... Rules > struct control : internal::control< Control, Rules ... > {};
   template< typename ... Rules > struct disable : internal::disable< Rules ... > {};
   template< template< typename ... > class Action, typename ... Rules > struct enable : internal::enable< Action, Rules ... > {};
   struct eof : internal::eof {};
   struct failure : internal::trivial< false > {};
   template< typename Cond, typename Then, typename ... Thens > struct if_must : internal::if_must< Cond, Then, Thens ... > {};
   template< typename Cond, typename Then, typename Else > struct if_must_else : internal::if_mode_else< error_mode::THROW, Cond, Then, Else > {};
   template< typename Cond, typename Then, typename Else > struct if_then_else : internal::if_mode_else< error_mode::RETURN, Cond, Then, Else > {};
   template< typename Rule, typename Sep, typename Pad = void > struct list : internal::list_pad< Rule, Sep, Pad, internal::star > {};
   template< typename Rule, typename Sep > struct list< Rule, Sep, void > : internal::list< Rule, Sep, internal::star > {};
   template< typename Rule, typename Sep, typename Pad = void > struct list_must : internal::list_pad< Rule, Sep, Pad, internal::star_must > {};
   template< typename Rule, typename Sep > struct list_must< Rule, Sep, void > : internal::list< Rule, Sep, internal::star_must > {};
   template< typename Rule, typename Sep, typename Pad = void > struct list_tail : internal::list_tail_pad< Rule, Sep, Pad > {};
   template< typename Rule, typename Sep > struct list_tail< Rule, Sep, void > : internal::list_tail< Rule, Sep > {};
   template< typename ... Rules > struct must : internal::must< Rules ... > {};
   template< typename ... Rules > struct not_at : internal::not_at< Rules ... > {};
   template< typename ... Rules > struct opt : internal::opt< Rules ... > {};
   template< typename Rule, typename Pad1, typename Pad2 = Pad1 > struct pad : internal::pad< Rule, Pad1, Pad2 > {};
   template< typename Rule, typename Pad > struct pad_opt : internal::pad_opt< Rule, Pad > {};
   template< typename ... Rules > struct plus : internal::plus< Rules ... > {};
   template< unsigned Num, typename ... Rules > struct rep : internal::rep< Num, Rules ... > {};
   template< unsigned Max, typename ... Rules > struct rep_max : internal::rep_min_max< 0, Max, Rules ... > {};
   template< unsigned Min, typename ... Rules > struct rep_min : internal::seq< internal::rep< Min, Rules ... >, internal::star< Rules ... > > {};
   template< unsigned Min, unsigned Max, typename ... Rules > struct rep_min_max : internal::rep_min_max< Min, Max, Rules ... > {};
   template< unsigned Max, typename ... Rules > struct rep_opt : internal::rep_opt< Max, Rules ... > {};
   template< typename ... Rules > struct seq : internal::seq< Rules ... > {};
   template< typename ... Rules > struct sor : internal::sor< Rules ... > {};
   template< typename ... Rules > struct star : internal::star< Rules ... > {};
   template< typename ... Rules > struct star_must : internal::star_must< Rules ... > {};
   struct success : internal::trivial< true > {};
   template< typename ... Rules > struct try_catch : internal::try_catch_type< parse_error, Rules ... > {};
   template< typename Exception, typename ... Rules > struct try_catch_type : internal::try_catch_type< Exception, Rules ... > {};
   template< typename Cond, typename ... Rules > struct until : internal::until< Cond, Rules ... > {};

} // pegtl

#endif