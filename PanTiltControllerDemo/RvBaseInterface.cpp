#include "RvBaseInterface.h"

RvBaseInterface::RvBaseInterface()
{
	//The following copypasta is from the github tutorial
	////start connection to the server.
 //   auto fileStream = std::make_shared<ostream>();

 //   // Open stream to output file.
 //   pplx::task<void> requestTask = fstream::open_ostream(U("results.html"))
 //       .then([=](ostream outFile)
 //       {
 //           *fileStream = outFile;

 //           // Create http_client to send the request.
 //           http_client client(U("http://www.bing.com/"));

 //           // Build request URI and start the request.
 //           uri_builder builder(U("/search"));
 //           builder.append_query(U("q"), U("cpprestsdk github"));
 //           return client.request(methods::GET, builder.to_string());
 //       })   // Handle response headers arriving.
 //       .then([=](http_response response)
 //           {
 //               printf("Received response status code:%u\n", response.status_code());

 //               // Write response body into the file.
 //               return response.body().read_to_end(fileStream->streambuf());
 //           })
 //           // Close the file stream.
 //       .then([=](size_t)
 //           {
 //               return fileStream->close();
 //           });
 //           
 //   // Wait for all the outstanding I/O to complete and handle any exceptions
 //   try
 //   {
 //       requestTask.wait();
 //   }
 //   catch (const std::exception& e)
 //   {
 //       printf("Error exception:%s\n", e.what());
 //   }

	

}

bool RvBaseInterface::getServerStatus()
{
	auto url = U("https://reqres.in");
	// Make a GET request.
	auto requestJson = http_client(url)
		.request(methods::GET,
			uri_builder(U("api")).append_path(U("users")).append_query(U("id"), 1).to_string()) //https://reqres.in/api/users?id=1

		// Get the response.
		.then([](http_response response) {
		// Check the status code.
		if (response.status_code() != 200) {
			throw std::runtime_error("Returned " + std::to_string(response.status_code()));
		}

		// Convert the response body to JSON object.
		return response.extract_json();
			})

		// Get the data field.
				.then([](json::value jsonObject) {
				return jsonObject[U("data")];
					})

				// Parse the user details.
						.then([](json::value jsonObject) {
						std::wcout << jsonObject[U("first_name")].as_string()
							<< " " << jsonObject[U("last_name")].as_string()
							<< " (" << jsonObject[U("id")].as_integer() << ")"
							<< std::endl;
							});

					// Wait for the concurrent tasks to finish.
					try {
						requestJson.wait();
					}
					catch (const std::exception& e) {
						printf("Error exception:%s\n", e.what());
					}
	return false;
}

void RvBaseInterface::getStatus()
{


}
