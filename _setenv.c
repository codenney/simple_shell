#include "main.h"

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @datum: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_input *datum)
{

	/**
	 * if (datum->args[1] == NULL || datum->args[2] == NULL)
	{
		get_error(datum, -1);
		return (1);
	}
	*/

	set_env(datum->args[1], datum->args[2], datum);

	return (1);
}
