// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__EventPHQMD
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "src/PEventHadrons.h"
#include "src/PEventBaryons.h"
#include "src/PRun.h"
#include "src/PBaryon.h"
#include "src/PHadron.h"
#include "EventFreeze/RunFreeze.h"
#include "EventFreeze/EventFreeze.h"
#include "EventFreeze/ParticleFreeze.h"
#include "unigen/URun.h"
#include "unigen/UEvent.h"
#include "unigen/UParticle.h"
#include "converter/PConverter.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_PEventHadrons(void *p = nullptr);
   static void *newArray_PEventHadrons(Long_t size, void *p);
   static void delete_PEventHadrons(void *p);
   static void deleteArray_PEventHadrons(void *p);
   static void destruct_PEventHadrons(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PEventHadrons*)
   {
      ::PEventHadrons *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PEventHadrons >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("PEventHadrons", ::PEventHadrons::Class_Version(), "PEventHadrons.h", 12,
                  typeid(::PEventHadrons), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PEventHadrons::Dictionary, isa_proxy, 4,
                  sizeof(::PEventHadrons) );
      instance.SetNew(&new_PEventHadrons);
      instance.SetNewArray(&newArray_PEventHadrons);
      instance.SetDelete(&delete_PEventHadrons);
      instance.SetDeleteArray(&deleteArray_PEventHadrons);
      instance.SetDestructor(&destruct_PEventHadrons);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PEventHadrons*)
   {
      return GenerateInitInstanceLocal(static_cast<::PEventHadrons*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PEventHadrons*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PEventBaryons(void *p = nullptr);
   static void *newArray_PEventBaryons(Long_t size, void *p);
   static void delete_PEventBaryons(void *p);
   static void deleteArray_PEventBaryons(void *p);
   static void destruct_PEventBaryons(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PEventBaryons*)
   {
      ::PEventBaryons *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PEventBaryons >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("PEventBaryons", ::PEventBaryons::Class_Version(), "PEventBaryons.h", 12,
                  typeid(::PEventBaryons), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PEventBaryons::Dictionary, isa_proxy, 4,
                  sizeof(::PEventBaryons) );
      instance.SetNew(&new_PEventBaryons);
      instance.SetNewArray(&newArray_PEventBaryons);
      instance.SetDelete(&delete_PEventBaryons);
      instance.SetDeleteArray(&deleteArray_PEventBaryons);
      instance.SetDestructor(&destruct_PEventBaryons);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PEventBaryons*)
   {
      return GenerateInitInstanceLocal(static_cast<::PEventBaryons*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PEventBaryons*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PRun(void *p = nullptr);
   static void *newArray_PRun(Long_t size, void *p);
   static void delete_PRun(void *p);
   static void deleteArray_PRun(void *p);
   static void destruct_PRun(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PRun*)
   {
      ::PRun *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PRun >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("PRun", ::PRun::Class_Version(), "PRun.h", 11,
                  typeid(::PRun), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PRun::Dictionary, isa_proxy, 4,
                  sizeof(::PRun) );
      instance.SetNew(&new_PRun);
      instance.SetNewArray(&newArray_PRun);
      instance.SetDelete(&delete_PRun);
      instance.SetDeleteArray(&deleteArray_PRun);
      instance.SetDestructor(&destruct_PRun);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PRun*)
   {
      return GenerateInitInstanceLocal(static_cast<::PRun*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PRun*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PBaryon(void *p = nullptr);
   static void *newArray_PBaryon(Long_t size, void *p);
   static void delete_PBaryon(void *p);
   static void deleteArray_PBaryon(void *p);
   static void destruct_PBaryon(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PBaryon*)
   {
      ::PBaryon *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PBaryon >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("PBaryon", ::PBaryon::Class_Version(), "PBaryon.h", 14,
                  typeid(::PBaryon), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PBaryon::Dictionary, isa_proxy, 4,
                  sizeof(::PBaryon) );
      instance.SetNew(&new_PBaryon);
      instance.SetNewArray(&newArray_PBaryon);
      instance.SetDelete(&delete_PBaryon);
      instance.SetDeleteArray(&deleteArray_PBaryon);
      instance.SetDestructor(&destruct_PBaryon);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PBaryon*)
   {
      return GenerateInitInstanceLocal(static_cast<::PBaryon*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PBaryon*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PHadron(void *p = nullptr);
   static void *newArray_PHadron(Long_t size, void *p);
   static void delete_PHadron(void *p);
   static void deleteArray_PHadron(void *p);
   static void destruct_PHadron(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PHadron*)
   {
      ::PHadron *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PHadron >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("PHadron", ::PHadron::Class_Version(), "PHadron.h", 14,
                  typeid(::PHadron), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PHadron::Dictionary, isa_proxy, 4,
                  sizeof(::PHadron) );
      instance.SetNew(&new_PHadron);
      instance.SetNewArray(&newArray_PHadron);
      instance.SetDelete(&delete_PHadron);
      instance.SetDeleteArray(&deleteArray_PHadron);
      instance.SetDestructor(&destruct_PHadron);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PHadron*)
   {
      return GenerateInitInstanceLocal(static_cast<::PHadron*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PHadron*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RunFreeze(void *p = nullptr);
   static void *newArray_RunFreeze(Long_t size, void *p);
   static void delete_RunFreeze(void *p);
   static void deleteArray_RunFreeze(void *p);
   static void destruct_RunFreeze(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RunFreeze*)
   {
      ::RunFreeze *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RunFreeze >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RunFreeze", ::RunFreeze::Class_Version(), "RunFreeze.h", 11,
                  typeid(::RunFreeze), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RunFreeze::Dictionary, isa_proxy, 4,
                  sizeof(::RunFreeze) );
      instance.SetNew(&new_RunFreeze);
      instance.SetNewArray(&newArray_RunFreeze);
      instance.SetDelete(&delete_RunFreeze);
      instance.SetDeleteArray(&deleteArray_RunFreeze);
      instance.SetDestructor(&destruct_RunFreeze);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RunFreeze*)
   {
      return GenerateInitInstanceLocal(static_cast<::RunFreeze*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RunFreeze*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_EventFreeze(void *p = nullptr);
   static void *newArray_EventFreeze(Long_t size, void *p);
   static void delete_EventFreeze(void *p);
   static void deleteArray_EventFreeze(void *p);
   static void destruct_EventFreeze(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EventFreeze*)
   {
      ::EventFreeze *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EventFreeze >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("EventFreeze", ::EventFreeze::Class_Version(), "EventFreeze.h", 16,
                  typeid(::EventFreeze), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::EventFreeze::Dictionary, isa_proxy, 4,
                  sizeof(::EventFreeze) );
      instance.SetNew(&new_EventFreeze);
      instance.SetNewArray(&newArray_EventFreeze);
      instance.SetDelete(&delete_EventFreeze);
      instance.SetDeleteArray(&deleteArray_EventFreeze);
      instance.SetDestructor(&destruct_EventFreeze);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EventFreeze*)
   {
      return GenerateInitInstanceLocal(static_cast<::EventFreeze*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::EventFreeze*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ParticleFreeze(void *p = nullptr);
   static void *newArray_ParticleFreeze(Long_t size, void *p);
   static void delete_ParticleFreeze(void *p);
   static void deleteArray_ParticleFreeze(void *p);
   static void destruct_ParticleFreeze(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ParticleFreeze*)
   {
      ::ParticleFreeze *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ParticleFreeze >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("ParticleFreeze", ::ParticleFreeze::Class_Version(), "ParticleFreeze.h", 14,
                  typeid(::ParticleFreeze), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::ParticleFreeze::Dictionary, isa_proxy, 4,
                  sizeof(::ParticleFreeze) );
      instance.SetNew(&new_ParticleFreeze);
      instance.SetNewArray(&newArray_ParticleFreeze);
      instance.SetDelete(&delete_ParticleFreeze);
      instance.SetDeleteArray(&deleteArray_ParticleFreeze);
      instance.SetDestructor(&destruct_ParticleFreeze);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ParticleFreeze*)
   {
      return GenerateInitInstanceLocal(static_cast<::ParticleFreeze*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::ParticleFreeze*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_URun(void *p = nullptr);
   static void *newArray_URun(Long_t size, void *p);
   static void delete_URun(void *p);
   static void deleteArray_URun(void *p);
   static void destruct_URun(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::URun*)
   {
      ::URun *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::URun >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("URun", ::URun::Class_Version(), "URun.h", 8,
                  typeid(::URun), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::URun::Dictionary, isa_proxy, 4,
                  sizeof(::URun) );
      instance.SetNew(&new_URun);
      instance.SetNewArray(&newArray_URun);
      instance.SetDelete(&delete_URun);
      instance.SetDeleteArray(&deleteArray_URun);
      instance.SetDestructor(&destruct_URun);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::URun*)
   {
      return GenerateInitInstanceLocal(static_cast<::URun*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::URun*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_UEvent(void *p = nullptr);
   static void *newArray_UEvent(Long_t size, void *p);
   static void delete_UEvent(void *p);
   static void deleteArray_UEvent(void *p);
   static void destruct_UEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::UEvent*)
   {
      ::UEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::UEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("UEvent", ::UEvent::Class_Version(), "UEvent.h", 12,
                  typeid(::UEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::UEvent::Dictionary, isa_proxy, 4,
                  sizeof(::UEvent) );
      instance.SetNew(&new_UEvent);
      instance.SetNewArray(&newArray_UEvent);
      instance.SetDelete(&delete_UEvent);
      instance.SetDeleteArray(&deleteArray_UEvent);
      instance.SetDestructor(&destruct_UEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::UEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::UEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::UEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_UParticle(void *p = nullptr);
   static void *newArray_UParticle(Long_t size, void *p);
   static void delete_UParticle(void *p);
   static void deleteArray_UParticle(void *p);
   static void destruct_UParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::UParticle*)
   {
      ::UParticle *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::UParticle >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("UParticle", ::UParticle::Class_Version(), "UParticle.h", 10,
                  typeid(::UParticle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::UParticle::Dictionary, isa_proxy, 4,
                  sizeof(::UParticle) );
      instance.SetNew(&new_UParticle);
      instance.SetNewArray(&newArray_UParticle);
      instance.SetDelete(&delete_UParticle);
      instance.SetDeleteArray(&deleteArray_UParticle);
      instance.SetDestructor(&destruct_UParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::UParticle*)
   {
      return GenerateInitInstanceLocal(static_cast<::UParticle*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::UParticle*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *PConverter_Dictionary();
   static void PConverter_TClassManip(TClass*);
   static void *new_PConverter(void *p = nullptr);
   static void *newArray_PConverter(Long_t size, void *p);
   static void delete_PConverter(void *p);
   static void deleteArray_PConverter(void *p);
   static void destruct_PConverter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PConverter*)
   {
      ::PConverter *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PConverter));
      static ::ROOT::TGenericClassInfo 
         instance("PConverter", "PConverter.h", 33,
                  typeid(::PConverter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PConverter_Dictionary, isa_proxy, 4,
                  sizeof(::PConverter) );
      instance.SetNew(&new_PConverter);
      instance.SetNewArray(&newArray_PConverter);
      instance.SetDelete(&delete_PConverter);
      instance.SetDeleteArray(&deleteArray_PConverter);
      instance.SetDestructor(&destruct_PConverter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PConverter*)
   {
      return GenerateInitInstanceLocal(static_cast<::PConverter*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PConverter*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PConverter_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::PConverter*>(nullptr))->GetClass();
      PConverter_TClassManip(theClass);
   return theClass;
   }

   static void PConverter_TClassManip(TClass* ){
   }

} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr PEventHadrons::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PEventHadrons::Class_Name()
{
   return "PEventHadrons";
}

//______________________________________________________________________________
const char *PEventHadrons::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PEventHadrons*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PEventHadrons::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PEventHadrons*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PEventHadrons::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PEventHadrons*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PEventHadrons::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PEventHadrons*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PEventBaryons::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PEventBaryons::Class_Name()
{
   return "PEventBaryons";
}

//______________________________________________________________________________
const char *PEventBaryons::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PEventBaryons*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PEventBaryons::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PEventBaryons*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PEventBaryons::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PEventBaryons*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PEventBaryons::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PEventBaryons*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PRun::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PRun::Class_Name()
{
   return "PRun";
}

//______________________________________________________________________________
const char *PRun::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PRun*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PRun::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PRun*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PRun::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PRun*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PRun::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PRun*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PBaryon::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PBaryon::Class_Name()
{
   return "PBaryon";
}

//______________________________________________________________________________
const char *PBaryon::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PBaryon*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PBaryon::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PBaryon*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PBaryon::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PBaryon*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PBaryon::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PBaryon*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PHadron::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PHadron::Class_Name()
{
   return "PHadron";
}

//______________________________________________________________________________
const char *PHadron::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PHadron*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PHadron::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PHadron*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PHadron::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PHadron*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PHadron::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PHadron*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RunFreeze::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RunFreeze::Class_Name()
{
   return "RunFreeze";
}

//______________________________________________________________________________
const char *RunFreeze::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RunFreeze*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RunFreeze::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RunFreeze*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RunFreeze::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RunFreeze*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RunFreeze::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RunFreeze*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr EventFreeze::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventFreeze::Class_Name()
{
   return "EventFreeze";
}

//______________________________________________________________________________
const char *EventFreeze::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventFreeze*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventFreeze::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventFreeze*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventFreeze::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventFreeze*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventFreeze::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventFreeze*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ParticleFreeze::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleFreeze::Class_Name()
{
   return "ParticleFreeze";
}

//______________________________________________________________________________
const char *ParticleFreeze::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ParticleFreeze*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleFreeze::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ParticleFreeze*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleFreeze::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ParticleFreeze*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleFreeze::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ParticleFreeze*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr URun::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *URun::Class_Name()
{
   return "URun";
}

//______________________________________________________________________________
const char *URun::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::URun*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int URun::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::URun*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *URun::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::URun*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *URun::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::URun*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr UEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *UEvent::Class_Name()
{
   return "UEvent";
}

//______________________________________________________________________________
const char *UEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int UEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr UParticle::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *UParticle::Class_Name()
{
   return "UParticle";
}

//______________________________________________________________________________
const char *UParticle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UParticle*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int UParticle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UParticle*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UParticle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UParticle*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UParticle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UParticle*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void PEventHadrons::Streamer(TBuffer &R__b)
{
   // Stream an object of class PEventHadrons.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PEventHadrons::Class(),this);
   } else {
      R__b.WriteClassBuffer(PEventHadrons::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PEventHadrons(void *p) {
      return  p ? new(p) ::PEventHadrons : new ::PEventHadrons;
   }
   static void *newArray_PEventHadrons(Long_t nElements, void *p) {
      return p ? new(p) ::PEventHadrons[nElements] : new ::PEventHadrons[nElements];
   }
   // Wrapper around operator delete
   static void delete_PEventHadrons(void *p) {
      delete (static_cast<::PEventHadrons*>(p));
   }
   static void deleteArray_PEventHadrons(void *p) {
      delete [] (static_cast<::PEventHadrons*>(p));
   }
   static void destruct_PEventHadrons(void *p) {
      typedef ::PEventHadrons current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PEventHadrons

//______________________________________________________________________________
void PEventBaryons::Streamer(TBuffer &R__b)
{
   // Stream an object of class PEventBaryons.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PEventBaryons::Class(),this);
   } else {
      R__b.WriteClassBuffer(PEventBaryons::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PEventBaryons(void *p) {
      return  p ? new(p) ::PEventBaryons : new ::PEventBaryons;
   }
   static void *newArray_PEventBaryons(Long_t nElements, void *p) {
      return p ? new(p) ::PEventBaryons[nElements] : new ::PEventBaryons[nElements];
   }
   // Wrapper around operator delete
   static void delete_PEventBaryons(void *p) {
      delete (static_cast<::PEventBaryons*>(p));
   }
   static void deleteArray_PEventBaryons(void *p) {
      delete [] (static_cast<::PEventBaryons*>(p));
   }
   static void destruct_PEventBaryons(void *p) {
      typedef ::PEventBaryons current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PEventBaryons

//______________________________________________________________________________
void PRun::Streamer(TBuffer &R__b)
{
   // Stream an object of class PRun.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PRun::Class(),this);
   } else {
      R__b.WriteClassBuffer(PRun::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PRun(void *p) {
      return  p ? new(p) ::PRun : new ::PRun;
   }
   static void *newArray_PRun(Long_t nElements, void *p) {
      return p ? new(p) ::PRun[nElements] : new ::PRun[nElements];
   }
   // Wrapper around operator delete
   static void delete_PRun(void *p) {
      delete (static_cast<::PRun*>(p));
   }
   static void deleteArray_PRun(void *p) {
      delete [] (static_cast<::PRun*>(p));
   }
   static void destruct_PRun(void *p) {
      typedef ::PRun current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PRun

//______________________________________________________________________________
void PBaryon::Streamer(TBuffer &R__b)
{
   // Stream an object of class PBaryon.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PBaryon::Class(),this);
   } else {
      R__b.WriteClassBuffer(PBaryon::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PBaryon(void *p) {
      return  p ? new(p) ::PBaryon : new ::PBaryon;
   }
   static void *newArray_PBaryon(Long_t nElements, void *p) {
      return p ? new(p) ::PBaryon[nElements] : new ::PBaryon[nElements];
   }
   // Wrapper around operator delete
   static void delete_PBaryon(void *p) {
      delete (static_cast<::PBaryon*>(p));
   }
   static void deleteArray_PBaryon(void *p) {
      delete [] (static_cast<::PBaryon*>(p));
   }
   static void destruct_PBaryon(void *p) {
      typedef ::PBaryon current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PBaryon

//______________________________________________________________________________
void PHadron::Streamer(TBuffer &R__b)
{
   // Stream an object of class PHadron.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PHadron::Class(),this);
   } else {
      R__b.WriteClassBuffer(PHadron::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PHadron(void *p) {
      return  p ? new(p) ::PHadron : new ::PHadron;
   }
   static void *newArray_PHadron(Long_t nElements, void *p) {
      return p ? new(p) ::PHadron[nElements] : new ::PHadron[nElements];
   }
   // Wrapper around operator delete
   static void delete_PHadron(void *p) {
      delete (static_cast<::PHadron*>(p));
   }
   static void deleteArray_PHadron(void *p) {
      delete [] (static_cast<::PHadron*>(p));
   }
   static void destruct_PHadron(void *p) {
      typedef ::PHadron current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PHadron

//______________________________________________________________________________
void RunFreeze::Streamer(TBuffer &R__b)
{
   // Stream an object of class RunFreeze.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RunFreeze::Class(),this);
   } else {
      R__b.WriteClassBuffer(RunFreeze::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RunFreeze(void *p) {
      return  p ? new(p) ::RunFreeze : new ::RunFreeze;
   }
   static void *newArray_RunFreeze(Long_t nElements, void *p) {
      return p ? new(p) ::RunFreeze[nElements] : new ::RunFreeze[nElements];
   }
   // Wrapper around operator delete
   static void delete_RunFreeze(void *p) {
      delete (static_cast<::RunFreeze*>(p));
   }
   static void deleteArray_RunFreeze(void *p) {
      delete [] (static_cast<::RunFreeze*>(p));
   }
   static void destruct_RunFreeze(void *p) {
      typedef ::RunFreeze current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RunFreeze

//______________________________________________________________________________
void EventFreeze::Streamer(TBuffer &R__b)
{
   // Stream an object of class EventFreeze.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EventFreeze::Class(),this);
   } else {
      R__b.WriteClassBuffer(EventFreeze::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_EventFreeze(void *p) {
      return  p ? new(p) ::EventFreeze : new ::EventFreeze;
   }
   static void *newArray_EventFreeze(Long_t nElements, void *p) {
      return p ? new(p) ::EventFreeze[nElements] : new ::EventFreeze[nElements];
   }
   // Wrapper around operator delete
   static void delete_EventFreeze(void *p) {
      delete (static_cast<::EventFreeze*>(p));
   }
   static void deleteArray_EventFreeze(void *p) {
      delete [] (static_cast<::EventFreeze*>(p));
   }
   static void destruct_EventFreeze(void *p) {
      typedef ::EventFreeze current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::EventFreeze

//______________________________________________________________________________
void ParticleFreeze::Streamer(TBuffer &R__b)
{
   // Stream an object of class ParticleFreeze.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ParticleFreeze::Class(),this);
   } else {
      R__b.WriteClassBuffer(ParticleFreeze::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ParticleFreeze(void *p) {
      return  p ? new(p) ::ParticleFreeze : new ::ParticleFreeze;
   }
   static void *newArray_ParticleFreeze(Long_t nElements, void *p) {
      return p ? new(p) ::ParticleFreeze[nElements] : new ::ParticleFreeze[nElements];
   }
   // Wrapper around operator delete
   static void delete_ParticleFreeze(void *p) {
      delete (static_cast<::ParticleFreeze*>(p));
   }
   static void deleteArray_ParticleFreeze(void *p) {
      delete [] (static_cast<::ParticleFreeze*>(p));
   }
   static void destruct_ParticleFreeze(void *p) {
      typedef ::ParticleFreeze current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::ParticleFreeze

//______________________________________________________________________________
void URun::Streamer(TBuffer &R__b)
{
   // Stream an object of class URun.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(URun::Class(),this);
   } else {
      R__b.WriteClassBuffer(URun::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_URun(void *p) {
      return  p ? new(p) ::URun : new ::URun;
   }
   static void *newArray_URun(Long_t nElements, void *p) {
      return p ? new(p) ::URun[nElements] : new ::URun[nElements];
   }
   // Wrapper around operator delete
   static void delete_URun(void *p) {
      delete (static_cast<::URun*>(p));
   }
   static void deleteArray_URun(void *p) {
      delete [] (static_cast<::URun*>(p));
   }
   static void destruct_URun(void *p) {
      typedef ::URun current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::URun

//______________________________________________________________________________
void UEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class UEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(UEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(UEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_UEvent(void *p) {
      return  p ? new(p) ::UEvent : new ::UEvent;
   }
   static void *newArray_UEvent(Long_t nElements, void *p) {
      return p ? new(p) ::UEvent[nElements] : new ::UEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_UEvent(void *p) {
      delete (static_cast<::UEvent*>(p));
   }
   static void deleteArray_UEvent(void *p) {
      delete [] (static_cast<::UEvent*>(p));
   }
   static void destruct_UEvent(void *p) {
      typedef ::UEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::UEvent

//______________________________________________________________________________
void UParticle::Streamer(TBuffer &R__b)
{
   // Stream an object of class UParticle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(UParticle::Class(),this);
   } else {
      R__b.WriteClassBuffer(UParticle::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_UParticle(void *p) {
      return  p ? new(p) ::UParticle : new ::UParticle;
   }
   static void *newArray_UParticle(Long_t nElements, void *p) {
      return p ? new(p) ::UParticle[nElements] : new ::UParticle[nElements];
   }
   // Wrapper around operator delete
   static void delete_UParticle(void *p) {
      delete (static_cast<::UParticle*>(p));
   }
   static void deleteArray_UParticle(void *p) {
      delete [] (static_cast<::UParticle*>(p));
   }
   static void destruct_UParticle(void *p) {
      typedef ::UParticle current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::UParticle

namespace ROOT {
   // Wrappers around operator new
   static void *new_PConverter(void *p) {
      return  p ? new(p) ::PConverter : new ::PConverter;
   }
   static void *newArray_PConverter(Long_t nElements, void *p) {
      return p ? new(p) ::PConverter[nElements] : new ::PConverter[nElements];
   }
   // Wrapper around operator delete
   static void delete_PConverter(void *p) {
      delete (static_cast<::PConverter*>(p));
   }
   static void deleteArray_PConverter(void *p) {
      delete [] (static_cast<::PConverter*>(p));
   }
   static void destruct_PConverter(void *p) {
      typedef ::PConverter current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PConverter

namespace ROOT {
   static TClass *vectorlEmaplEintcOvectorlEintgRsPgRsPgR_Dictionary();
   static void vectorlEmaplEintcOvectorlEintgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p);
   static void destruct_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<map<int,vector<int> > >*)
   {
      vector<map<int,vector<int> > > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<map<int,vector<int> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<map<int,vector<int> > >", -2, "vector", 348,
                  typeid(vector<map<int,vector<int> > >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEmaplEintcOvectorlEintgRsPgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<map<int,vector<int> > >) );
      instance.SetNew(&new_vectorlEmaplEintcOvectorlEintgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEmaplEintcOvectorlEintgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEmaplEintcOvectorlEintgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEmaplEintcOvectorlEintgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEmaplEintcOvectorlEintgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<map<int,vector<int> > > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<map<int,vector<int> > >","std::__1::vector<std::__1::map<int, std::__1::vector<int, std::__1::allocator<int>>, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, std::__1::vector<int, std::__1::allocator<int>>>>>, std::__1::allocator<std::__1::map<int, std::__1::vector<int, std::__1::allocator<int>>, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, std::__1::vector<int, std::__1::allocator<int>>>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<map<int,vector<int> > >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEmaplEintcOvectorlEintgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<map<int,vector<int> > >*>(nullptr))->GetClass();
      vectorlEmaplEintcOvectorlEintgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEmaplEintcOvectorlEintgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<map<int,vector<int> > > : new vector<map<int,vector<int> > >;
   }
   static void *newArray_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<map<int,vector<int> > >[nElements] : new vector<map<int,vector<int> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p) {
      delete (static_cast<vector<map<int,vector<int> > >*>(p));
   }
   static void deleteArray_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p) {
      delete [] (static_cast<vector<map<int,vector<int> > >*>(p));
   }
   static void destruct_vectorlEmaplEintcOvectorlEintgRsPgRsPgR(void *p) {
      typedef vector<map<int,vector<int> > > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<map<int,vector<int> > >

namespace ROOT {
   static TClass *vectorlEmaplEintcOintgRsPgR_Dictionary();
   static void vectorlEmaplEintcOintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEmaplEintcOintgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEmaplEintcOintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEmaplEintcOintgRsPgR(void *p);
   static void deleteArray_vectorlEmaplEintcOintgRsPgR(void *p);
   static void destruct_vectorlEmaplEintcOintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<map<int,int> >*)
   {
      vector<map<int,int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<map<int,int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<map<int,int> >", -2, "vector", 348,
                  typeid(vector<map<int,int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEmaplEintcOintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<map<int,int> >) );
      instance.SetNew(&new_vectorlEmaplEintcOintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEmaplEintcOintgRsPgR);
      instance.SetDelete(&delete_vectorlEmaplEintcOintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEmaplEintcOintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEmaplEintcOintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<map<int,int> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<map<int,int> >","std::__1::vector<std::__1::map<int, int, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, int>>>, std::__1::allocator<std::__1::map<int, int, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, int>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<map<int,int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEmaplEintcOintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<map<int,int> >*>(nullptr))->GetClass();
      vectorlEmaplEintcOintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEmaplEintcOintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEmaplEintcOintgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<map<int,int> > : new vector<map<int,int> >;
   }
   static void *newArray_vectorlEmaplEintcOintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<map<int,int> >[nElements] : new vector<map<int,int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEmaplEintcOintgRsPgR(void *p) {
      delete (static_cast<vector<map<int,int> >*>(p));
   }
   static void deleteArray_vectorlEmaplEintcOintgRsPgR(void *p) {
      delete [] (static_cast<vector<map<int,int> >*>(p));
   }
   static void destruct_vectorlEmaplEintcOintgRsPgR(void *p) {
      typedef vector<map<int,int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<map<int,int> >

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 348,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<int>","std::__1::vector<int, std::__1::allocator<int>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = nullptr);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 348,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<float>","std::__1::vector<float, std::__1::allocator<float>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr))->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete (static_cast<vector<float>*>(p));
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] (static_cast<vector<float>*>(p));
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *vectorlEParticleFreezegR_Dictionary();
   static void vectorlEParticleFreezegR_TClassManip(TClass*);
   static void *new_vectorlEParticleFreezegR(void *p = nullptr);
   static void *newArray_vectorlEParticleFreezegR(Long_t size, void *p);
   static void delete_vectorlEParticleFreezegR(void *p);
   static void deleteArray_vectorlEParticleFreezegR(void *p);
   static void destruct_vectorlEParticleFreezegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ParticleFreeze>*)
   {
      vector<ParticleFreeze> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ParticleFreeze>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ParticleFreeze>", -2, "vector", 348,
                  typeid(vector<ParticleFreeze>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEParticleFreezegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<ParticleFreeze>) );
      instance.SetNew(&new_vectorlEParticleFreezegR);
      instance.SetNewArray(&newArray_vectorlEParticleFreezegR);
      instance.SetDelete(&delete_vectorlEParticleFreezegR);
      instance.SetDeleteArray(&deleteArray_vectorlEParticleFreezegR);
      instance.SetDestructor(&destruct_vectorlEParticleFreezegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ParticleFreeze> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<ParticleFreeze>","std::__1::vector<ParticleFreeze, std::__1::allocator<ParticleFreeze>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<ParticleFreeze>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEParticleFreezegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<ParticleFreeze>*>(nullptr))->GetClass();
      vectorlEParticleFreezegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEParticleFreezegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEParticleFreezegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<ParticleFreeze> : new vector<ParticleFreeze>;
   }
   static void *newArray_vectorlEParticleFreezegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<ParticleFreeze>[nElements] : new vector<ParticleFreeze>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEParticleFreezegR(void *p) {
      delete (static_cast<vector<ParticleFreeze>*>(p));
   }
   static void deleteArray_vectorlEParticleFreezegR(void *p) {
      delete [] (static_cast<vector<ParticleFreeze>*>(p));
   }
   static void destruct_vectorlEParticleFreezegR(void *p) {
      typedef vector<ParticleFreeze> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<ParticleFreeze>

namespace ROOT {
   static TClass *vectorlEPHadrongR_Dictionary();
   static void vectorlEPHadrongR_TClassManip(TClass*);
   static void *new_vectorlEPHadrongR(void *p = nullptr);
   static void *newArray_vectorlEPHadrongR(Long_t size, void *p);
   static void delete_vectorlEPHadrongR(void *p);
   static void deleteArray_vectorlEPHadrongR(void *p);
   static void destruct_vectorlEPHadrongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PHadron>*)
   {
      vector<PHadron> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PHadron>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PHadron>", -2, "vector", 348,
                  typeid(vector<PHadron>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPHadrongR_Dictionary, isa_proxy, 0,
                  sizeof(vector<PHadron>) );
      instance.SetNew(&new_vectorlEPHadrongR);
      instance.SetNewArray(&newArray_vectorlEPHadrongR);
      instance.SetDelete(&delete_vectorlEPHadrongR);
      instance.SetDeleteArray(&deleteArray_vectorlEPHadrongR);
      instance.SetDestructor(&destruct_vectorlEPHadrongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PHadron> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<PHadron>","std::__1::vector<PHadron, std::__1::allocator<PHadron>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<PHadron>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPHadrongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<PHadron>*>(nullptr))->GetClass();
      vectorlEPHadrongR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPHadrongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPHadrongR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<PHadron> : new vector<PHadron>;
   }
   static void *newArray_vectorlEPHadrongR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<PHadron>[nElements] : new vector<PHadron>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPHadrongR(void *p) {
      delete (static_cast<vector<PHadron>*>(p));
   }
   static void deleteArray_vectorlEPHadrongR(void *p) {
      delete [] (static_cast<vector<PHadron>*>(p));
   }
   static void destruct_vectorlEPHadrongR(void *p) {
      typedef vector<PHadron> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<PHadron>

namespace ROOT {
   static TClass *vectorlEPBaryongR_Dictionary();
   static void vectorlEPBaryongR_TClassManip(TClass*);
   static void *new_vectorlEPBaryongR(void *p = nullptr);
   static void *newArray_vectorlEPBaryongR(Long_t size, void *p);
   static void delete_vectorlEPBaryongR(void *p);
   static void deleteArray_vectorlEPBaryongR(void *p);
   static void destruct_vectorlEPBaryongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PBaryon>*)
   {
      vector<PBaryon> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PBaryon>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PBaryon>", -2, "vector", 348,
                  typeid(vector<PBaryon>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPBaryongR_Dictionary, isa_proxy, 0,
                  sizeof(vector<PBaryon>) );
      instance.SetNew(&new_vectorlEPBaryongR);
      instance.SetNewArray(&newArray_vectorlEPBaryongR);
      instance.SetDelete(&delete_vectorlEPBaryongR);
      instance.SetDeleteArray(&deleteArray_vectorlEPBaryongR);
      instance.SetDestructor(&destruct_vectorlEPBaryongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PBaryon> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<PBaryon>","std::__1::vector<PBaryon, std::__1::allocator<PBaryon>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<PBaryon>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPBaryongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<PBaryon>*>(nullptr))->GetClass();
      vectorlEPBaryongR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPBaryongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPBaryongR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<PBaryon> : new vector<PBaryon>;
   }
   static void *newArray_vectorlEPBaryongR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<PBaryon>[nElements] : new vector<PBaryon>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPBaryongR(void *p) {
      delete (static_cast<vector<PBaryon>*>(p));
   }
   static void deleteArray_vectorlEPBaryongR(void *p) {
      delete [] (static_cast<vector<PBaryon>*>(p));
   }
   static void destruct_vectorlEPBaryongR(void *p) {
      typedef vector<PBaryon> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<PBaryon>

namespace ROOT {
   static TClass *maplEintcOvectorlEintgRsPgR_Dictionary();
   static void maplEintcOvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_maplEintcOvectorlEintgRsPgR(void *p = nullptr);
   static void *newArray_maplEintcOvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_maplEintcOvectorlEintgRsPgR(void *p);
   static void deleteArray_maplEintcOvectorlEintgRsPgR(void *p);
   static void destruct_maplEintcOvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,vector<int> >*)
   {
      map<int,vector<int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,vector<int> >", -2, "map", 969,
                  typeid(map<int,vector<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOvectorlEintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,vector<int> >) );
      instance.SetNew(&new_maplEintcOvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_maplEintcOvectorlEintgRsPgR);
      instance.SetDelete(&delete_maplEintcOvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_maplEintcOvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,vector<int> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<int,vector<int> >","std::__1::map<int, std::__1::vector<int, std::__1::allocator<int>>, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, std::__1::vector<int, std::__1::allocator<int>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<int,vector<int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<int,vector<int> >*>(nullptr))->GetClass();
      maplEintcOvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOvectorlEintgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,vector<int> > : new map<int,vector<int> >;
   }
   static void *newArray_maplEintcOvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,vector<int> >[nElements] : new map<int,vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOvectorlEintgRsPgR(void *p) {
      delete (static_cast<map<int,vector<int> >*>(p));
   }
   static void deleteArray_maplEintcOvectorlEintgRsPgR(void *p) {
      delete [] (static_cast<map<int,vector<int> >*>(p));
   }
   static void destruct_maplEintcOvectorlEintgRsPgR(void *p) {
      typedef map<int,vector<int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<int,vector<int> >

namespace ROOT {
   static TClass *maplEintcOintoB30cBgR_Dictionary();
   static void maplEintcOintoB30cBgR_TClassManip(TClass*);
   static void *new_maplEintcOintoB30cBgR(void *p = nullptr);
   static void *newArray_maplEintcOintoB30cBgR(Long_t size, void *p);
   static void delete_maplEintcOintoB30cBgR(void *p);
   static void deleteArray_maplEintcOintoB30cBgR(void *p);
   static void destruct_maplEintcOintoB30cBgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,int[30]>*)
   {
      map<int,int[30]> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,int[30]>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,int[30]>", -2, "map", 969,
                  typeid(map<int,int[30]>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOintoB30cBgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,int[30]>) );
      instance.SetNew(&new_maplEintcOintoB30cBgR);
      instance.SetNewArray(&newArray_maplEintcOintoB30cBgR);
      instance.SetDelete(&delete_maplEintcOintoB30cBgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOintoB30cBgR);
      instance.SetDestructor(&destruct_maplEintcOintoB30cBgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,int[30]> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<int,int[30]>","std::__1::map<int, int [30], std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, int [30]>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<int,int[30]>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOintoB30cBgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<int,int[30]>*>(nullptr))->GetClass();
      maplEintcOintoB30cBgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOintoB30cBgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOintoB30cBgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,int[30]> : new map<int,int[30]>;
   }
   static void *newArray_maplEintcOintoB30cBgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,int[30]>[nElements] : new map<int,int[30]>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOintoB30cBgR(void *p) {
      delete (static_cast<map<int,int[30]>*>(p));
   }
   static void deleteArray_maplEintcOintoB30cBgR(void *p) {
      delete [] (static_cast<map<int,int[30]>*>(p));
   }
   static void destruct_maplEintcOintoB30cBgR(void *p) {
      typedef map<int,int[30]> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<int,int[30]>

namespace ROOT {
   static TClass *maplEintcOintgR_Dictionary();
   static void maplEintcOintgR_TClassManip(TClass*);
   static void *new_maplEintcOintgR(void *p = nullptr);
   static void *newArray_maplEintcOintgR(Long_t size, void *p);
   static void delete_maplEintcOintgR(void *p);
   static void deleteArray_maplEintcOintgR(void *p);
   static void destruct_maplEintcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,int>*)
   {
      map<int,int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,int>", -2, "map", 969,
                  typeid(map<int,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,int>) );
      instance.SetNew(&new_maplEintcOintgR);
      instance.SetNewArray(&newArray_maplEintcOintgR);
      instance.SetDelete(&delete_maplEintcOintgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOintgR);
      instance.SetDestructor(&destruct_maplEintcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<int,int>","std::__1::map<int, int, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, int>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<int,int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<int,int>*>(nullptr))->GetClass();
      maplEintcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOintgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,int> : new map<int,int>;
   }
   static void *newArray_maplEintcOintgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,int>[nElements] : new map<int,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOintgR(void *p) {
      delete (static_cast<map<int,int>*>(p));
   }
   static void deleteArray_maplEintcOintgR(void *p) {
      delete [] (static_cast<map<int,int>*>(p));
   }
   static void destruct_maplEintcOintgR(void *p) {
      typedef map<int,int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<int,int>

namespace {
  void TriggerDictionaryInitialization_libEventPHQMD_Impl() {
    static const char* headers[] = {
"src/PEventHadrons.h",
"src/PEventBaryons.h",
"src/PRun.h",
"src/PBaryon.h",
"src/PHadron.h",
"EventFreeze/RunFreeze.h",
"EventFreeze/EventFreeze.h",
"EventFreeze/ParticleFreeze.h",
"unigen/URun.h",
"unigen/UEvent.h",
"unigen/UParticle.h",
"converter/PConverter.h",
nullptr
    };
    static const char* includePaths[] = {
"/Users/susanne/GitHub/EventPHQMD_52Winn/converter",
"/Users/susanne/GitHub/EventPHQMD_52Winn/EventFreeze",
"/Users/susanne/GitHub/EventPHQMD_52Winn/unigen",
"/Users/susanne/GitHub/EventPHQMD_52Winn/src",
"/Users/susanne/GitHub/EventPHQMD_52Winn",
"/usr/local/Cellar/root/6.30.04/include/root",
"/usr/local/Cellar/root/6.30.04/include/root",
"/Users/susanne/GitHub/EventPHQMD_52Winn/build/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libEventPHQMD dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$src/PEventHadrons.h")))  PEventHadrons;
class __attribute__((annotate("$clingAutoload$src/PEventBaryons.h")))  PEventBaryons;
class __attribute__((annotate("$clingAutoload$src/PRun.h")))  PRun;
class __attribute__((annotate("$clingAutoload$src/PBaryon.h")))  PBaryon;
class __attribute__((annotate("$clingAutoload$src/PHadron.h")))  PHadron;
class __attribute__((annotate("$clingAutoload$EventFreeze/RunFreeze.h")))  RunFreeze;
class __attribute__((annotate("$clingAutoload$EventFreeze/EventFreeze.h")))  EventFreeze;
class __attribute__((annotate("$clingAutoload$EventFreeze/ParticleFreeze.h")))  ParticleFreeze;
class __attribute__((annotate("$clingAutoload$unigen/URun.h")))  URun;
class __attribute__((annotate("$clingAutoload$unigen/UEvent.h")))  UEvent;
class __attribute__((annotate("$clingAutoload$unigen/UParticle.h")))  UParticle;
class __attribute__((annotate("$clingAutoload$converter/PConverter.h")))  PConverter;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libEventPHQMD dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "src/PEventHadrons.h"
#include "src/PEventBaryons.h"
#include "src/PRun.h"
#include "src/PBaryon.h"
#include "src/PHadron.h"
#include "EventFreeze/RunFreeze.h"
#include "EventFreeze/EventFreeze.h"
#include "EventFreeze/ParticleFreeze.h"
#include "unigen/URun.h"
#include "unigen/UEvent.h"
#include "unigen/UParticle.h"
#include "converter/PConverter.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"EventFreeze", payloadCode, "@",
"PBaryon", payloadCode, "@",
"PConverter", payloadCode, "@",
"PEventBaryons", payloadCode, "@",
"PEventHadrons", payloadCode, "@",
"PHadron", payloadCode, "@",
"PRun", payloadCode, "@",
"ParticleFreeze", payloadCode, "@",
"RunFreeze", payloadCode, "@",
"UEvent", payloadCode, "@",
"UParticle", payloadCode, "@",
"URun", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libEventPHQMD",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libEventPHQMD_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libEventPHQMD_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libEventPHQMD() {
  TriggerDictionaryInitialization_libEventPHQMD_Impl();
}
