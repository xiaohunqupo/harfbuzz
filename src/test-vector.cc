/*
 * Copyright © 2021  Behdad Esfahbod
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 */

#include "hb.hh"
#include "hb-vector.hh"
#include "hb-set.hh"
#include "hb-map.hh"
#include <string>


int
main (int argc, char **argv)
{
  hb_always_assert (sizeof (hb_vector_t<int>) == sizeof (hb_sorted_vector_t<int>));

  /* Test copy constructor. */
  {
    hb_vector_t<int> v1 {1, 2};
    hb_vector_t<int> v2 {v1};
    hb_vector_t<int> V2 {v1};
    hb_always_assert (v1.length == 2);
    hb_always_assert (v1[0] == 1);
    hb_always_assert (v1[1] == 2);
    hb_always_assert (v2.length == 2);
    hb_always_assert (v2[0] == 1);
    hb_always_assert (v2[1] == 2);
  }

  /* Test copy assignment. */
  {
    hb_vector_t<int> v1 {1, 2};
    hb_vector_t<int> v2 = v1;
    hb_vector_t<int> V2 = v1;
    hb_always_assert (v1.length == 2);
    hb_always_assert (v1[0] == 1);
    hb_always_assert (v1[1] == 2);
    hb_always_assert (v2.length == 2);
    hb_always_assert (v2[0] == 1);
    hb_always_assert (v2[1] == 2);
  }

  /* Test move constructor. */
  {
    hb_vector_t<int> s {1, 2};
    hb_sorted_vector_t<int> S {1, 2};
    hb_vector_t<int> v (std::move (s));
    hb_sorted_vector_t<int> V (std::move (S));
    hb_always_assert (s.length == 0);
    hb_always_assert (S.length == 0);
    hb_always_assert (v.length == 2);
    hb_always_assert (v[0] == 1);
    hb_always_assert (v[1] == 2);
  }

  /* Test move assignment. */
  {
    hb_vector_t<int> s {1, 2};
    hb_sorted_vector_t<int> S {1, 2};
    hb_vector_t<int> v;
    hb_sorted_vector_t<int> V;
    v = std::move (s);
    V = std::move (S);
    hb_always_assert (s.length == 0);
    hb_always_assert (S.length == 0);
    hb_always_assert (v.length == 2);
    hb_always_assert (V.length == 2);
    hb_always_assert (v[0] == 1);
    hb_always_assert (v[1] == 2);
  }

  /* Test initializing from iterable. */
  {
    hb_set_t s;

    s.add (18);
    s.add (12);

    hb_vector_t<int> v (s);
    hb_sorted_vector_t<int> V (s);

    hb_always_assert (v.length == 2);
    hb_always_assert (V.length == 2);
    hb_always_assert (v[0] == 12);
    hb_always_assert (V[0] == 12);
    hb_always_assert (v[1] == 18);
    hb_always_assert (V[1] == 18);
  }

  /* Test initializing from iterator. */
  {
    hb_set_t s;

    s.add (18);
    s.add (12);

    hb_vector_t<int> v (hb_iter (s));
    hb_vector_t<int> V (hb_iter (s));

    hb_always_assert (v.length == 2);
    hb_always_assert (V.length == 2);
    hb_always_assert (v[0] == 12);
    hb_always_assert (V[0] == 12);
    hb_always_assert (v[1] == 18);
    hb_always_assert (V[1] == 18);
  }

  /* Test initializing from initializer list and swapping. */
  {
    hb_vector_t<int> v1 {1, 2, 3};
    hb_vector_t<int> v2 {4, 5};
    hb_swap (v1, v2);
    hb_always_assert (v1.length == 2);
    hb_always_assert (v1[0] == 4);
    hb_always_assert (v2.length == 3);
    hb_always_assert (v2[2] == 3);
  }

  /* Test initializing sorted-vector from initializer list and swapping. */
  {
    hb_sorted_vector_t<int> v1 {1, 2, 3};
    hb_sorted_vector_t<int> v2 {4, 5};
    hb_swap (v1, v2);
    hb_always_assert (v1.length == 2);
    hb_always_assert (v1[0] == 4);
    hb_always_assert (v2.length == 3);
    hb_always_assert (v2[2] == 3);
  }

  {
    hb_vector_t<std::string> v;

    std::string s;
    for (unsigned i = 1; i < 100; i++)
    {
      s += "x";
      v.push (s);
    }

    hb_vector_t<std::string> v2;

    v2 = v;

    v2.remove_ordered (50);
    v2.remove_unordered (50);
  }

  {
    hb_vector_t<hb_set_t> v;
    hb_set_t s {1, 5, 7};
    v.push (s);
    v << s;
    hb_always_assert (s.get_population () == 3);
    v << std::move (s);
    hb_always_assert (s.get_population () == 0);
  }

  {
    hb_vector_t<hb_map_t> v;
    hb_map_t m;
    v.push (m);
  }
  {
    hb_vector_t<hb_map_t> v;
    hb_map_t m;
    v.push (m);
  }

  return 0;
}
