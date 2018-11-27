/********************************************************************
       Copyright (c) 2000, Ant Works Software
       http://www.antws.com

       created  :  May 10, 2001
       filename :  variable.h
       author   :  Lee Patterson (lee@antws.com)

       purpose  :  Class to hold a variable

       notes    :  
*********************************************************************/

#ifndef VARIABLE_H
#define VARIABLE_H

#include <ssobjects/ssobjects.h>

class Variable
{
  public:
    enum {TYPE_INT,TYPE_STRING};
	enum {MAX_LENGTH=1024};
  protected:
    char   m_sName[MAX_LENGTH];
    int    m_iValue;
    char   m_sValue[MAX_LENGTH];
    int    m_iType;

  public:
    Variable(const char* pszVariableName,const int iType)
      : m_sName(),m_iValue(0),m_sValue(),m_iType(iType) 
    { 
    	#ifdef DEBUG
        	printf("created variable [%s] of type %s\n",pszVariableName,(iType==TYPE_INT)?"int":"string"); 
        #endif
        strncpy(m_sName,pszVariableName,sizeof(m_sName));
        NULL_TERMINATE(m_sName,sizeof(m_sName));
        
        int length = strlen(m_sName);
        while('\r'==m_sName[length-1] || '\n'==m_sName[length-1])
        {
            m_sName[length-1]='\0';
            length = strlen(m_sName);
        }
    }

    virtual ~Variable(){}

    void setStringValue(const char* pszValue) {strncpy(m_sValue,pszValue,sizeof(m_sValue)); NULL_TERMINATE(m_sValue,sizeof(m_sValue));}
    void setIntValue(const int iValue) {m_iValue = iValue;}
    int intValue() const {return m_iValue;}
    const char* stringValue() const {return m_sValue;}
    const char* name() const {return m_sName;}
    int type() const {return m_iType;}
    Variable& operator ++ (int)
    {
      if(type() == TYPE_INT)
        m_iValue++;
      return *this;
    }
    Variable& operator -- (int)
    {
      if(type() == TYPE_INT)
        m_iValue--;
      return *this;
    }
};

#endif
