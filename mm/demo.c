#include <stdio.h>
#include <stdlib.h>
#include <libmm-glib.h>
#include <glib.h>
#include <stdbool.h>


int main (int argc, char *argv[]){




	GDBusConnection *connection = NULL;
	MMManager *manager = NULL;
	GError *error = NULL;
	MMObject *objects = NULL;
	MMSmsProperties *properties = NULL;
	gchar *name_owner = NULL;
	GCancellable *cancel = NULL;


	connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &error);
	if (!connection) {
		g_printerr ("error: couldn't get bus: %s\n", error->message);
		exit (EXIT_FAILURE);
	}

	manager = mm_manager_new_sync(connection, G_DBUS_OBJECT_MANAGER_CLIENT_FLAGS_DO_NOT_AUTO_START, NULL, &error); //create a modem

	if (!manager){

		g_printerr("Failed to create MMManager: %s\n", error->message);
		g_clear_error(&error);
		return 1;
	}


	printf("succesfully init. MMManager\n");

	/* scan for devices */



	gboolean scan_true = mm_manager_scan_devices_sync(manager, cancel, &error);

	if (scan_true == true){
		printf("scan success\n");
	}



	/*

	   const GList *modems = mm_manager_get_modems(manager);
	   if (!modems) {
	   g_printerr("No modems found\n");
	   g_object_unref(manager);
	   return 1;
	   }
	 */
	return 0;

}
