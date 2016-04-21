/*
 * nl_exceptions.h
 *
 *  Created on: Feb 25, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
 */

/*
 *       class: Exception
 *       brief: Abstract Exception handling class.
 */

/*
 *    function: errMsg()
 *       brief: The getter for the exception message
 *         pre: None
 *        post: Returns the Exception message
 *      return: Returns the Exception message
 */

/*
 *    function: operator << (std::string const &)
 *       brief: The setter for the exception message
 *       Input: Message string
 *         pre: None
 *        post: inserts input into end of message
 *      return: this
 */

/*
 *       class: FatalError
 *       brief: Exception handling class derived from exception.
 */

/*
 *    function: FatalError( char* or std::string)
 *       brief: Constructor that sets the message for what()
 *         pre: There must be at least and empty string (ie. "")
 *        post: Constructs an exception object to be thrown
 *      return: None
 */

/*
 *    function: ~FatalError()
 *       brief: Destructor
 *         pre: None
 *        post: Destructors an object
 *      return: None
 */

/*
 *       class: RangeException
 *       brief: Exception handling class derived from exception.
 */

/*
 *    function: RangeException( char* or std::string)
 *       brief: Constructor that sets the message for what()
 *         pre: There must be at least and empty string (ie. "")
 *        post: Constructs an exception object to be thrown
 *      return: None
 */

/*
 *    function: ~RangeException()
 *       brief: Destructor
 *         pre: None
 *        post: Destructors an object
 *      return: None
 */

/*
 *       class: DimensionMismatch
 *       brief: Exception handling class derived from exception.
 */

/*
 *    function: DimensionMismatch( char* or std::string)
 *       brief: Constructor that sets the message for what()
 *         pre: There must be at least and empty string (ie. "")
 *        post: Constructs an exception object to be thrown
 *      return: None
 */

/*
 *    function: ~DimensionMismatch()
 *       brief: Destructor
 *         pre: None
 *        post: Destructors an object
 *      return: None
 */

#ifndef NL_EXCEPTIONS_H_
#define NL_EXCEPTIONS_H_

#include <string>
#include <exception>

namespace numlib
{
  class Exception
  {
    public:
    virtual ~Exception() {}

    virtual const std::string errMsg() const noexcept = 0;

    virtual Exception& operator << (std::string const &msg) = 0;
  };

  class RangeException: public Exception
  {
    public:
      RangeException(): msg_() {}
      RangeException(std::string const &m): msg_(m) {}
      virtual ~RangeException() {}

      virtual const std::string errMsg() const noexcept
          {return "Range Error: " + msg_ + " \n";};

      virtual Exception& operator << (std::string const &msg)
      {
        msg_ = msg_ + msg;
        return *this;
      }

    private:
      std::string msg_;
  };

  class DimensionMismatch: public Exception
  {
    public:
      DimensionMismatch(): msg_() {}
      explicit DimensionMismatch(const std::string& msg): msg_(msg)
      {
      }
      virtual ~DimensionMismatch() {}

      virtual const std::string errMsg() const noexcept
        {return "Dimension Error: " + msg_ + " \n";};

      virtual Exception& operator << (std::string const &msg)
      {
        msg_ = msg_ + msg;
        return *this;
      }

    private:
      std::string msg_;
  };

  class FatalError: public Exception
  {
    public:
      FatalError(): msg_() {}
      explicit FatalError(const std::string& msg): msg_(msg)
      {
      }

      virtual ~FatalError() throw (){}

      virtual const std::string errMsg() const throw()
      {
        return "Fatal Error! " + msg_ + " \n";
      }

      virtual Exception& operator << (std::string const &msg)
      {
        msg_ = msg_ + msg;
        return *this;
      }

    protected:
      std::string msg_;
  };
}



#endif /* NL_EXCEPTIONS_H_ */
