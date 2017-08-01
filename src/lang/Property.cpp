// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by zzu_softboy on 2017/08/01.

#include "zapi/lang/Property.h"

namespace zapi
{
namespace lang
{

namespace internal
{

class PropertyPrivate
{
public:
   PropertyPrivate(const zapi::GetterMethodCallback0 &getter)
      : m_getterType(0)
   {
      m_getter.getter0 = getter;
   }
   
   PropertyPrivate(const zapi::GetterMethodCallback1 &getter)
      : m_getterType(0)
   {
      m_getter.getter1 = getter;
   }
   
   PropertyPrivate(const zapi::SetterMethodCallback0 &setter)
      : m_setterType(0)
   {
      m_setter.setter0 = setter;
   }
   
   PropertyPrivate(const zapi::SetterMethodCallback1 &setter)
      : m_setterType(1)
   {
      m_setter.setter1 = setter;
   }
   
   PropertyPrivate(const zapi::GetterMethodCallback0 &getter, const zapi::SetterMethodCallback0 &setter)
      : m_getterType(0),
        m_setterType(0)
   {
      m_getter.getter0 = getter;
      m_setter.setter0 = setter;
   }
   
   PropertyPrivate(const zapi::GetterMethodCallback0 &getter, const zapi::SetterMethodCallback1 &setter)
      : m_getterType(0),
        m_setterType(1)
   {
      m_getter.getter0 = getter;
      m_setter.setter1 = setter;
   }
   
   PropertyPrivate(const zapi::GetterMethodCallback1 &getter, const zapi::SetterMethodCallback0 &setter)
      : m_getterType(1),
        m_setterType(0)
   {
      m_getter.getter1 = getter;
      m_setter.setter0 = setter;
   }
   
   PropertyPrivate(const zapi::GetterMethodCallback1 &getter, const zapi::SetterMethodCallback1 &setter)
      : m_getterType(1),
        m_setterType(1)
   {
      m_getter.getter1 = getter;
      m_setter.setter1 = setter;
   }
   
   PropertyPrivate(const PropertyPrivate &other)
      : m_getter(other.m_getter),
        m_setter(other.m_setter),
        m_getterType(other.m_getterType),
        m_setterType(other.m_setterType)
   {}
   
   union {
      zapi::GetterMethodCallback0 getter0;
      zapi::GetterMethodCallback1 getter1;
   } m_getter;
   union {
      zapi::SetterMethodCallback0 setter0;
      zapi::SetterMethodCallback1 setter1;
   } m_setter;
   int m_getterType = -1;
   int m_setterType = -1;
};

} // internal

Property::Property(const zapi::GetterMethodCallback0 &getter)
   : m_implPtr(new PropertyPrivate(getter))
{}

Property::Property(const zapi::GetterMethodCallback1 &getter)
   : m_implPtr(new PropertyPrivate(getter))
{}

Property::Property(const zapi::SetterMethodCallback0 &setter)
   : m_implPtr(new PropertyPrivate(setter))
{}

Property::Property(const zapi::SetterMethodCallback1 &setter)
   : m_implPtr(new PropertyPrivate(setter))
{}

Property::Property(const zapi::GetterMethodCallback0 &getter, const zapi::SetterMethodCallback0 &setter)
   : m_implPtr(new PropertyPrivate(getter, setter))
{}

Property::Property(const zapi::GetterMethodCallback0 &getter, const zapi::SetterMethodCallback1 &setter)
   : m_implPtr(new PropertyPrivate(getter, setter))
{}

Property::Property(const zapi::GetterMethodCallback1 &getter, const zapi::SetterMethodCallback0 &setter)
   : m_implPtr(new PropertyPrivate(getter, setter))
{}

Property::Property(const zapi::GetterMethodCallback1 &getter, const zapi::SetterMethodCallback1 &setter)
   : m_implPtr(new PropertyPrivate(getter, setter))
{}

Property::Property(const Property &other)
   : m_implPtr(new PropertyPrivate(*other.m_implPtr))
{}

Property::~Property()
{}

} // lang
} // zapi