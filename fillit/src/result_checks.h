//
//  result_checks.h
//  tests
//
//  Created by Delia Arugula on 30/09/2019.
//  Copyright © 2019 Delia Arugula. All rights reserved.
//

#ifndef result_checks_h
#define result_checks_h
BOOL	is_out_of_square(t_r r, int row, int col);
BOOL	is_overlap(t_r r, int row, int col);
BOOL	has_a_neighbour(t_r r, int row, int col);
BOOL	can_append(t_r r, int row, int col, t_t t);

#endif /* result_checks_h */
