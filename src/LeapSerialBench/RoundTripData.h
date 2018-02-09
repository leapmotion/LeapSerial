// Copyright (C) 2012-2018 Leap Motion, Inc. All rights reserved.
#pragma once
#include <LeapSerial/LeapSerial.h>
#include <map>
#include <string>
#include <vector>

namespace {
  class PhoneNumber {
  public:
    enum PhoneType {
      MOBILE,
      HOME,
      WORK
    };

    std::string number;
    PhoneType type;

    bool operator==(const PhoneNumber& rhs) const {
      return number == rhs.number && type == rhs.type;
    }

    static leap::descriptor GetDescriptor(void) {
      return{
        { 1, &PhoneNumber::number },
        { 2, &PhoneNumber::type }
      };
    }
  };

  class Pet {
  public:
    std::string name;

    enum class Species {
      DOG = 0,
      CAT = 1
    };
    Species species;

    static leap::descriptor GetDescriptor(void) {
      return{
        "Pet",
        {
          { 1, &Pet::name },
          { 2, &Pet::species }
        }
      };
    }
  };

  class Person {
  public:
    std::string name;
    int id;
    std::string email;
    std::vector<PhoneNumber> phone;
    std::map<std::string, Pet> pets;

    bool operator==(const Person& rhs) const {
      return
        name == rhs.name &&
        id == rhs.id &&
        email == rhs.email &&
        phone == rhs.phone;
    }

    static leap::descriptor GetDescriptor(void) {
      return{
        "Person",
        {
          { 1, "name", &Person::name },
          { 2, "id", &Person::id },
          { 3, "email", &Person::email },
          { 4, "phone", &Person::phone },
          { 5, "pets", &Person::pets }
        }
      };
    }
  };
}
