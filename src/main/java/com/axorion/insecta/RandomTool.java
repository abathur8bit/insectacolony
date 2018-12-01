// Copyright (c) 2002, Ant Works Software
// Author : Lee Patterson (lee@ant-works.com)
// Date   : December 20, 2002

package com.axorion.insecta;

/**Random number tools.*/
public class RandomTool
{
  /**Returns a number within a given range.
   * Using Math.random() a randome number is chosen and returned that 
   * will be >= min and <= max. So if min is 10 and max is 15, the 
   * numbers 10, 11, 12, 13, 14, 15 can be returned.
   *
   *@param min  smallest number that can be returned.
   *@param max  largest number that can be returned.
   *
   *@return Integer between given range.
   */
  public static int rnd(int min,int max)
  {
    return min+(int)(Math.random()*(max+1-min));
  }
}

