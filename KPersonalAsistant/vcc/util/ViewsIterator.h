/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsIterator.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ViewsIterator class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef VIEWSITERATOR_H_
#define VIEWSITERATOR_H_


#include "IViewsIterator.h"
#include <QList>
#include <QVector>
#include <QListIterator>
#include <list>
#include <vector>

/**
 * We want packing into this class every list of class hierarchy. 
 * This way we obtaining a generic structure for manipulating lists and we have control about as are used.
 * To create a new iterator, you must instanciate it and by means of contructor parameter specify the list 
 * that you want iterating. 
 * 
 * 
 * How do you use this class?
 * In your class implementation you can say either:
 * 
 *  ViewsIterator<T> it(*this);
 *    or
 *  std::list<int> lst;
 *  ViewsIterator<int> it(lst);
 *
 * The first option is if your class inherits from list otherwise, using the second form.
 * 
 */
template<typename Ti>
class ViewsIterator : public IViewsIterator<Ti>, 
                      protected QListIterator<Ti>
{
  
public:
  
  /**
   * The way to create a ViewsIterator from standard list is using this constructor.
   * It is thus in order to avoid */
  ViewsIterator(const std::list<Ti> &_stdList);

  /**
   * The way to create a ViewsIterator from standard vector is using this constructor.
   * It is thus in order to avoid */
  ViewsIterator(const std::vector<Ti> &_stdVector);

  /**
   * Return a list object referenced.
   * @return Ti
   */
  Ti next();
  
  /**
   * This method returns true if iterator has object or false in otherwise.
   * @return bool
   */
  bool hasNext();

  /**
   * This method returns iterator size, it depends of standard list passed by parameter in constructor. 
   * 
   * @return uint32_t
   */
  uint32_t size();

  /**
   * Returns a instance value hold in position passed through parameter.
   * 
   * @param uint16_t
   * @return Ti
   */
  Ti getElementAt(uint16_t _pos);

  /**
   * Class destructor
   */
  virtual ~ViewsIterator();
  
protected:
 
  /**Void constructor
   * Cannot use this constructor for instancing ViewsIterator and for this reason is protected.
   * The only way to create a IPProtocolIterator instance is by means of ViewsIterator(const std::list<Ti> &_stdList).
   */
  //ViewsIterator();

  /**
   * Create a ViewsIterator instance.
   * Must specify which list you want iterating by means of _list parameter.
   * Cannot use this constructor to instanciate ViewsIterator and for this reason is protected.
   * The only way to create a IPProtocolIterator instance is by means of ViewsIterator(const std::list<Ti> &_stdList).
   * 
   * @param &_list
   */
  ViewsIterator(const QList<Ti> &_list);
  
private:

  /**This variable holds a list size of vector/list passed through parameter in constructor.*/
	uint32_t listSize_;
};


/**Void constructor
 * Cannot use this constructor for instancing ViewsIterator and for this reason is protected.
 * The only way to create a IPProtocolIterator instance is by means of ViewsIterator(const std::list<Ti> &_stdList).
 */
/*template<typename Ti>
ViewsIterator<Ti>::ViewsIterator()
{
  listSize_ = 0;
}*/

/**
 * Create a ViewsIterator instance.
 * Must specify which list you want iterating by means of _list parameter.
 * Cannot use this constructor to instanciate ViewsIterator and for this reason is protected.
 * The only way to create a IPProtocolIterator instance is by means of ViewsIterator(const std::list<Ti> &_stdList).
 * 
 * @param &_list
 */
template<typename Ti>
ViewsIterator<Ti>::ViewsIterator(const QList<Ti> &list) : 
  QListIterator<Ti>(list) 
{
  
}

/**
 * The way to create a ViewsIterator from standard list is using this constructor.
 * It is thus in order to avoid */

template<typename Ti>
ViewsIterator<Ti>::ViewsIterator(const std::list<Ti> &stdList):
  QListIterator<Ti>(QList<Ti>::fromStdList(stdList)),
  listSize_(stdList.size())
{

}

/**
 * The way to create a ViewsIterator from standard vector is using this constructor.
 * It is thus in order to avoid */
template<typename Ti>
ViewsIterator<Ti>::ViewsIterator(const std::vector<Ti> &stdVector):
  QListIterator<Ti>(QList<Ti>::fromVector(QVector<Ti>::fromStdVector(stdVector))),
  listSize_(stdVector.size())
{

}

/**
 * Class destructor
 */
template<typename Ti>
ViewsIterator<Ti>::~ViewsIterator()
{
  
}

/**
 * Return a list object referenced.
 * @return Ti
 */
template<typename Ti>
Ti ViewsIterator<Ti>::next()
{
  return QListIterator<Ti>::next();
}

/**
 * This method returns true if iterator has object or false in otherwise.
 * @return bool
 */
template<typename Ti>
bool ViewsIterator<Ti>::hasNext()
{
  return static_cast<bool>(QListIterator<Ti>::hasNext());
}

/**
 * This method returns iterator size, it depends of standard list passed by parameter in constructor. 
 * 
 * @return uint32_t
 */
template<typename Ti>
uint32_t ViewsIterator<Ti>::size()
{
  return listSize_;
}

/**
 * Returns a instance value hold in position passed through parameter.
 * 
 * @param uint16_t
 * @return Ti
 */
template<typename Ti>
Ti ViewsIterator<Ti>::getElementAt(uint16_t pos)
{
  Ti aux_element;
  if (pos < size()){
    for (int index = 0; index <= pos-1;index++)
    {
      next();
    }
    aux_element = next();
  }
  
  return aux_element;
}

#endif /*VIEWSITERATOR_H_*/
