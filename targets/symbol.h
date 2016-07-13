// $Id: symbol.h,v 1.6 2016/05/20 04:55:37 ist173253 Exp $ -*- c++ -*-
#ifndef __ZU_SEMANTICS_SYMBOL_H__
#define __ZU_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace zu {

  class symbol {
    int _flag;
    basic_type *_type;
    std::string _name;
    std::string _label;
    long _value;

  public:	inline symbol(int flag, basic_type *type, std::string &name, std::string &label, int value )
		: _flag(flag), _type(type), _name(name), _label(label), _value(value) { }

  public:
    int flag() { return _flag; }
    basic_type *type() { return _type; }
    std::string &name() { return _name; }
    std::string &label() { return _label; }
    int value() { return _value; }

    /*public:
      inline symbol(const basic_type *type, const std::string &name, long value) :
          _type(type), _name(name), _value(value) {
      }
      virtual ~symbol() {
        delete _type;
      }
      inline const basic_type *type() const {
        return _type;
      }
      inline const std::string &name() const {
        return _name;
      }
      inline long value() const {
        return _value;
      }
      inline long value(long v) {
        return _value = v;
      }*/

    };
} // zu

#endif
