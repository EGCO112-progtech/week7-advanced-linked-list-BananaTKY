// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assg7.h"

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int ID; // char entered by user
   char A[50] ;

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter ID and name : " );
            scanf( "%d %s", &ID , A);
            insert( &startPtr, ID , A); // insert ID in list
            printList( startPtr );
            printList_R( startPtr );
            break ;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter ID to be deleted: " );
               scanf( "%d", &ID );

               // if character is found, remove it
               if ( deletes( &startPtr, ID ) ) { // remove ID
                  printf( "%d deleted.\n", ID );
                  printList( startPtr );
                  printList_R( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", ID );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while
  /* Clear all nodes at the end of nodes*/
   free_L(&startPtr) ;
} // end main
